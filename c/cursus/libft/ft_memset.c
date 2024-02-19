/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:46:02 by username          #+#    #+#             */
/*   Updated: 2024/02/19 14:49:44 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, int n) 
{
  int i;
  char *str;
  char character;

  str = (char *)s;
  character = (unsigned char)c;
  
  while (i < n) {
    str[i] = character;
    i++;
  }

  return (void *)str;
}
