/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:35:56 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/19 08:17:21 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int print_char(char c, t_format_config config) {
  int pad;
  int printed;
  t_format_modifier_config modifier;

  printed = 0;
  modifier = config.modifier_config;
  if (!config.has_config)
    return ft_putchar_fd(c, 1);

  pad = modifier.pad.len - 1;
  if (pad <= 0)
    return ft_putchar_fd(c, 1);

  if (modifier.pad.is_right) {
    printed += ft_putchar_fd(c, 1);
    printed += print_repeat(' ', pad);
  } else {
    printed += print_repeat(' ', pad);
    printed += ft_putchar_fd(c, 1);
  }

  return printed;
}
