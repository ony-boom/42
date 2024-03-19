/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:35:56 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/19 11:17:56 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// TODO: make print_tab generic so it can work with all modifier
int print_pad(t_print_pad_params params)
{
    int printed;
    printed = 0;

    if (params.is_right)
    {
        printed += ft_putchar_fd(c, 1);
        printed += print_repeat(params.padding_char, params.padding_count);
    }
    else
    {
        printed += print_repeat(params.padding_char, params.padding_count);
        printed += ft_putchar_fd(c, 1);
    }
    return printed;
}

int print_char(char c, t_format_config config)
{
  int pad;
  int printed;
  char padding;
  t_format_modifier_config modifier;

  printed = 0;
  padding = ' ';
  modifier = config.modifier_config;
  if (!config.has_config)
    return ft_putchar_fd(c, 1);
  pad = modifier.pad.len - 1;
  if (modifier.pad.is_zero)
      padding = '0';
  if (pad <= 0)
    return ft_putchar_fd(c, 1);
  printed += print_pad(padding, c, modifier.pad.is_right, pad);
  return printed;
}
