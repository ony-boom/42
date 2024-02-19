/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:00:04 by username          #+#    #+#             */
/*   Updated: 2024/02/19 15:08:39 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, int n)
{
  int i;
  char *cdest;
  char *csrc;

  i = 0;
  cdest = (char *)dest;
  csrc = (char *)src;

  while(i < n)
  {
    cdest[i] = csrc[i];
    i++;
  }

  return cdest;
}
