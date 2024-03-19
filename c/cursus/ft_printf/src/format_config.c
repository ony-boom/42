/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:24:24 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/19 08:18:52 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void init_format_config(t_format_config *config) {
  config->format_len = 1;
  config->specifier = 0;
  config->has_config = FALSE;
  config->modifier_config = (t_format_modifier_config){
      .max_width = 0,
      .prepend_hex_prefix = FALSE,
      .pad = {.len = 0, .is_right = FALSE, .is_zero = FALSE},
      .int_modifier = {.show_sign = FALSE, .use_space_for_positive = FALSE},
  };
}

void make_config(const char *str, t_format_config *config) {
  config->has_config = TRUE;
  if (is_valid_format_modifier(*str)) {
    config->format_len += 1;
    str++;
  }
  if (*str == MINUS || *str == ZERO || ft_isdigit(*str))
    config->modifier_config.pad =
        get_pad_modifier((char *)str, &config->format_len);
  else if (*str == DOT)
    config->modifier_config.max_width =
        get_max_width((char *)str, &config->format_len);
  else if (*str == SPACE || *str == PLUS)
    config->modifier_config.int_modifier =
        get_int_modifier((char *)str, &config->format_len);
  else if (*str == SHARP) {
    config->format_len += 1;
    config->modifier_config.prepend_hex_prefix = TRUE;
  }
  // printf()
  // config->specifier = (t_format_specifier) * (str + config->format_len - 1);
}

t_format_config get_format_config(const char *str) {
  t_format_config config;

  init_format_config(&config);
  if (is_valid_format_specifier(*str)) {
    config.specifier = (t_format_specifier)*str;
    return (config);
  }
  make_config(str, &config);
  return (config);
}
