/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaber <mjaber@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:13:27 by mjaber            #+#    #+#             */
/*   Updated: 2025/11/10 11:43:01 by mjaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
# define BUFFER_SIZE 10

char  *get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);


#endif // !GET_NEXT_LINE_H 
