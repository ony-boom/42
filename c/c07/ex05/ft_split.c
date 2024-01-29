/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:31:58 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/28 23:43:35 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int is_sep(char *sep_like, char *sep)
{
  while (*sep) {
    if (*sep_like != *sep) 
      return 0; 
    sep++;
    sep_like++;
  }
  return 1;
}

int get_size(const char *strr, char *charset, int **str_sizes)
{
  int i;
  int size;
  char *str;

  i = 0;
  size = 0;
  str = (char *)strr;
  // strs = malloc(sizeof(char));

  while (*str) {
    if (is_sep(str, charset)) {
      str += ft_strlen(charset);
      (*str_sizes)[i++] = size;
      size = 0;
      continue;
    }
    size++;
    str++; 
  }
}


void ft_split(const char *str, char *charset)
{
  get_size(str, charset);
}

int main()
{
  ft_split("Ony**world**baby", "**");
}
