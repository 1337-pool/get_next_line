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
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (*(str++) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	char	*str1;
	char	*str2;
	int		i;

	if (!s1)
      return (ft_strdup(s2));
  i = 0;
  str1 = (char *)s1;
  str2 = (char *)s2;
  mem = (char *)malloc(sizeof(char)
                       * (ft_strlen(str1) + ft_strlen(str2) + 1));
  if (!mem)
		return (NULL);
	while (*str1)
		mem[i++] = *(str1++);
	while (*str2)
		mem[i++] = *(str2++);
	mem[i] = '\0';  
	return (mem);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char )c)
			return ((char *)s);
		s++;
	}
	if (*s == (char )c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;
	char	*str;

	str = (char *)s;
	i = 0;
	p = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*str)
		p[i++] = *str++;
	p[i] = '\0';
	return (p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*mem;
	size_t		i;
	size_t		lens;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start || len == 0)
		return ((char *)calloc(1, 1));
	lens = ft_strlen(s + start);
	if (len > lens)
		len = lens;
	mem = malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	while (*s && i < len)
	{
		mem[i] = s[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
