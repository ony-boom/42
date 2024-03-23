/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:01:41 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/23 14:06:12 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 7
#endif // !BUFFER_SIZE

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

int	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
void	*ft_calloc(int nitems, int size);
int	ft_strlcpy(char *dst, const char *src, int size);
#endif // !GET_NEXT_LINE_H
