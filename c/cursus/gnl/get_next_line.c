/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:03:01 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/23 14:08:58 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	int		src_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= (unsigned int)src_len)
		return (ft_strdup(""));
	if (start + len > (unsigned int)src_len)
		len = src_len - start + 1;
	else
		len += 1;
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
  int i;
  char *str;
  int readed;
  int has_nl;
  // static char *rest;

  str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
  if (!str)
    return NULL;
  readed = read(fd, str, BUFFER_SIZE);
  if (readed < 0)
    return NULL;

  i = 0;

  while (i < readed && str[i] != '\n')
    i++;
  return str;
}
