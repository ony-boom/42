/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:08:29 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/08 07:38:59 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

typedef struct number_format {
  t_format_sign sign;
  t_pad zero_pad;
  t_pad space_pad;
} t_number_format;

void set_pad(t_pad *pad, t_format_config_modifier *modifier, int to_print_len) {
  pad->padding_char = ' ';
  if (modifier->modifier_specifier == ZERO)
    pad->padding_char = '0';
  pad->count = modifier->value - to_print_len -
               (int)(modifier->modifier_specifier == PLUS ||
                     modifier->modifier_specifier == SPACE);
  if (pad->count <= 0)
    pad->count = 0;
  pad->from_right = (t_bool)(modifier->modifier_specifier == MINUS);
}

void set_max_width(t_number_format *format, t_format_config_modifier *modifier,
                   int to_print_len) {
  format->zero_pad.count = modifier->value - to_print_len;

  if (format->zero_pad.count <= 0)
    format->zero_pad.count = 0;
  format->zero_pad.from_right = FALSE;
  format->zero_pad.padding_char = '0';
  format->space_pad.count -= format->zero_pad.count;
  if (format->space_pad.count <= 0)
    format->space_pad.count = 0;
}

void init_format(t_number_format *format) {
  format->sign = (t_format_sign){.show = FALSE, .positive_sign = '+'};
  format->space_pad =
      (t_pad){.count = 0, .padding_char = ' ', .from_right = FALSE};
  format->zero_pad =
      (t_pad){.count = 0, .padding_char = '0', .from_right = FALSE};
}

static t_number_format build_format(t_format_config *config, int to_print_len) {
  int i;
  t_number_format format;
  t_format_config_modifier current_modifier;

  init_format(&format);
  i = 0;
  while (i < config->modifiers_size) {
    current_modifier = config->modifiers[i];
    if (current_modifier.modifier_specifier == DIGIT ||
        current_modifier.modifier_specifier == ZERO ||
        current_modifier.modifier_specifier == MINUS)
      set_pad(&format.space_pad, &current_modifier, to_print_len);
    if (current_modifier.modifier_specifier == DOT)
      set_max_width(&format, &current_modifier, to_print_len);
    if (current_modifier.modifier_specifier == PLUS ||
        current_modifier.modifier_specifier == SPACE) {
      set_pad(&format.space_pad, &current_modifier, to_print_len);
      format.sign.show = TRUE;
      if (current_modifier.modifier_specifier == SPACE)
        format.sign.positive_sign = ' ';
    }
    i++;
  }
  return (format);
}

int print_max_width(int n, t_pad *pad) {
  int abs_n;
  int printed;
  t_bool is_negative;

  printed = 0;
  abs_n = ft_abs(n);
  is_negative = n < 0;

  if (is_negative && n != MY_INT_MIN)
    printed += ft_putchar_fd('-', 1);
  printed += print_repeat(pad->padding_char, pad->count);
  printed += ft_putnbr_fd(abs_n, 1);

  return printed;
}

int print_number(int n, t_format_config *config) {
  int n_len;
  int printed;
  t_number_format format;

  printed = 0;
  n_len = get_int_len(n);
  format = build_format(config, n_len);

  if (format.space_pad.from_right) {
    if (format.sign.show)
      printed += ft_putchar_fd(format.sign.positive_sign, 1);
    printed += print_max_width(n, &format.zero_pad);
    printed +=
        print_repeat(format.space_pad.padding_char, format.space_pad.count);
  } else {
    printed +=
        print_repeat(format.space_pad.padding_char, format.space_pad.count);
    if (format.sign.show)
      printed += ft_putchar_fd(format.sign.positive_sign, 1);
    printed += print_max_width(n, &format.zero_pad);
  }

  return (printed);
}
