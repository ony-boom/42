/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:15:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/01 21:19:45 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void print_based_on_type(t_format format, va_list params)
{
  if (format == CHAR)
  {
    return;
  }

  if (format == STR)
  {
    return;
  }

  if(format == DECIMAL)
  {
    return;
  }
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
