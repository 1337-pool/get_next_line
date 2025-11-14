/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaber <mjaber@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:12:58 by mjaber            #+#    #+#             */
/*   Updated: 2025/11/13 16:52:12 by mjaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **res, char **lc)
{
	char	*temp;
	int		nl_pos;

	nl_pos = ft_strchr(*res, '\n');
	if (nl_pos != -1)
	{
		*lc = ft_substr(*res, nl_pos + 1, ft_strlen(*res) - nl_pos - 1);
		temp = ft_substr(*res, 0, nl_pos + 1);
		free(*res);
		*res = temp;
	}
	return (*res);
}

void	get_line(int fd, char **lc, char **res)
{
	char	*buffer;
	char	*temp;
	int		rd;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buffer[rd] = '\0';
		temp = ft_strjoin(*res, buffer);
		free(*res);
		*res = temp;
		if (ft_strchr(*res, '\n') != -1)
			break ;
	}
	free(buffer);
	extract_line(res, lc);
}

static char	*handle_leftover(char **lc, char **res)
{
	char	*temp;
	int		nl_pos;

	nl_pos = ft_strchr(*lc, '\n');
	if (nl_pos != -1)
	{
		free(*res);
		*res = ft_substr(*lc, 0, nl_pos + 1);
		temp = ft_substr(*lc, nl_pos + 1, ft_strlen(*lc) - nl_pos - 1);
		free(*lc);
		*lc = temp;
		return (*res);
	}
	temp = ft_strjoin(*res, *lc);
	free(*res);
	free(*lc);
	*res = temp;
	*lc = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*lc;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_strdup("");
	if (!res)
		return (NULL);
	if (lc && handle_leftover(&lc, &res))
		return (res);
	get_line(fd, &lc, &res);
	if (!res || *res == '\0')
	{
		free(res);
		if (lc)
			free(lc);
		lc = NULL;
		return (NULL);
	}
	return (res);
}