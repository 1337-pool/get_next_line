/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaber <mjaber@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:54:29 by mjaber            #+#    #+#             */
/*   Updated: 2025/11/13 16:51:27 by mjaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	mem = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!mem)
		return (NULL);
	i = -1;
	while (s1[++i])
		mem[i] = s1[i];
	j = -1;
	while (s2[++j])
		mem[i + j] = s2[j];
	mem[i + j] = '\0';
	return (mem);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	if (!s)
		return (NULL);
	i = 0;
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;
	size_t	lens;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start || len == 0)
	{
		mem = (char *)malloc(1);
		if (!mem)
			return (NULL);
		mem[0] = '\0';
		return (mem);
	}
	lens = ft_strlen(s + start);
	if (len > lens)
		len = lens;
	mem = malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i])
		mem[i] = s[start + i];
	mem[i] = '\0';
	return (mem);
}