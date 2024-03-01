/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:15:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/01 17:28:53 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void print_based_on_type(t_format format, va_list params)
{
}

int ft_printf(const char *str, ...)
{
  va_list params;
  char format_specifier;

  format_specifier = '%';

  va_start(params, str);

  while (*str) {
    if (*str == format_specifier) {
      print_based_on_type(*str++, params);
      continue;
    } else {
      ft_putchar_fd(*str, 1);
    }
    str++;
  }


  va_end(params);

  return ft_strlen(str);
}
