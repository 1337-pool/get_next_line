/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaber <mjaber@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:12:58 by mjaber            #+#    #+#             */
/*   Updated: 2025/11/12 14:38:57 by mjaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void  get_line(int fd, char **lc, char **res)
{
  char  *buffer;
  char  *str;
  int rd;
  rd = 1;

  str = (char*)malloc(1);
  *str = '\0';
  buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
  while (!ft_strchr(str, '\n') && rd > 0)
  {
    rd = read(fd, buffer, BUFFER_SIZE);
    str = ft_strjoin(str, buffer);
  }
  char *test = ft_substr(str, 0, ft_strchr(str, '\n'));
  *res = ft_strjoin(*res, test);
  *lc = str + ft_strchr(str, '\n') + 1;
  free(str);
  free(buffer);
}

char  *get_next_line(int fd)
{
  static char *lc;
  char  *res;

  res = (char *)malloc(sizeof(char));
  *res = '\0';
  if (fd < 0 || BUFFER_SIZE <= 0)
  {
    lc = NULL;
    return (NULL);
  }
  if (lc && ft_strchr(lc, '\n'))
  {
    res = ft_substr(lc, 0, ft_strchr(lc, '\n'));
    lc = lc + ft_strchr(lc, '\n');
    printf("%s\n", lc);
    return (res);
  }
  if (lc)
  {
    res = ft_strjoin(res, lc);
    lc = NULL;
  }
  get_line(fd, &lc, &res);
  printf("fd is %d, res is %s, chyata is %s\n", fd, res, lc);
  return (res);
}

int main()
{
  int fd = open("test.txt", O_RDWR | O_CREAT);
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
}
