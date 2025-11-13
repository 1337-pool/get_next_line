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

void    get_line(int fd, char **lc, char **res)
{
        char    *buffer;
        char    *temp;
        int             rd;
        int             nl_pos;

        rd = 1;
        buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!buffer)
                return ;
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
        nl_pos = ft_strchr(*res, '\n');
        if (nl_pos != -1)
        {
                *lc = ft_substr(*res, nl_pos + 1, ft_strlen(*res) - nl_pos - 1);
                temp = ft_substr(*res, 0, nl_pos + 1);
                free(*res);
                *res = temp;
        }
}

char    *get_next_line(int fd)
{
        static char     *lc;
        char            *res;
        char            *temp;
        int                     nl_pos;

        if (fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);
        res = ft_strdup("");
        if (!res)
                return (NULL);
        if (lc)
        {
                nl_pos = ft_strchr(lc, '\n');
                if (nl_pos != -1)
                {
                        free(res);
                        res = ft_substr(lc, 0, nl_pos + 1);
                        temp = ft_substr(lc, nl_pos + 1, ft_strlen(lc) - nl_pos - 1);
                        free(lc);
                        lc = temp;
                        return (res);
                }
                temp = ft_strjoin(res, lc);
                free(res);
                free(lc);
                res = temp;
                lc = NULL;
        }
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

int main()
{
  int fd = open("text.txt", O_RDWR | O_CREAT);
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  //printf("%s\n", get_next_line(fd));
  //printf("%s\n", get_next_line(fd));
//  printf("%s\n", get_next_line(fd));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaber <mjaber@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:45:54 by mjaber            #+#    #+#             */
/*   Updated: 2025/11/13 16:52:12 by mjaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);
int             ft_strchr(const char *s, int c);
char    *ft_substr(const char *s, unsigned int start, size_t len);

#endif
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

size_t  ft_strlen(const char *s)
{
        size_t  i;

        if (!s)
                return (0);
        i = 0;
        while (s[i])
                i++;
        return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *mem;
        size_t  i;
        size_t  j;

        if (!s1 && !s2)
                return (NULL);
        if (!s1)
                return (ft_strdup(s2));
        if (!s2)
                return (ft_strdup(s1));
        mem = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (!mem)
                return (NULL);
        i = 0;
        j = 0;
        while (s1[i])
        {
                mem[i] = s1[i];
                i++;
        }
        while (s2[j])
        {
                mem[i + j] = s2[j];
                j++;
        }
        mem[i + j] = '\0';
        return (mem);
}

int     ft_strchr(const char *s, int c)
{
        int     i;

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

char    *ft_strdup(const char *s)
{
        int             i;
        char    *p;

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

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
        char    *mem;
        size_t  i;
        size_t  lens;

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
        i = 0;
        while (i < len && s[start + i])
        {
                mem[i] = s[start + i];
                i++;
        }
        mem[i] = '\0';
        return (mem);
}
