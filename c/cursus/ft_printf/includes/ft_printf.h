/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:28:43 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/18 07:38:28 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef enum specifier
{
	CHAR = 'c',
	INTEGER = 'i',
	STR = 's',
	DECIMAL = 'd',
	POINTER = 'p',
	UNSIGNED_INT = 'u',
	HEX = 'x',
	UPPER_HEX = 'X',
	PERCENT = '%'
}								t_format_specifier;

typedef enum modifier
{
	MINUS = '-',
	ZERO = '0',
	DOT = '.',
	SHARP = '#',
	SPACE = ' ',
	PLUS = '+'
}								t_format_modifier;

typedef enum my_bool
{
	FALSE = 0,
	TRUE = 1
}								t_bool;

typedef struct pad_modifier
{
	int							len;
	t_bool						is_zero;
	t_bool						is_right;
}								t_pad_modifier;

typedef struct int_modifier
{
	t_bool						show_sign;
	t_bool						use_space_for_positive;
}								t_int_modifier;

typedef struct format_modifier_config
{
	int							max_width;
	t_pad_modifier				pad;
	t_int_modifier				int_modifier;
	t_bool						prepend_hex_prefix;
}								t_format_modifier_config;

typedef struct format_config
{
	int							format_len;
	t_bool						has_config;
	t_format_specifier			specifier;
	t_format_modifier_config	modifier_config;
}								t_format_config;

t_bool							is_valid_char(char c, const t_format_specifier *arr,
									int size);
t_bool							is_valid_format_specifier(char c);
t_bool							is_valid_format_modifier(char c);

t_format_config					get_format_config(const char *str);
t_pad_modifier					get_pad_modifier(char *format, int *format_len);
t_int_modifier					get_int_modifier(const char *format,
									int *format_len);
int								get_hex(int n, int use_upper);
int	print_type(t_format_config config, va_list params);
int								ft_printf(const char *str, ...);
int								get_max_width(char *format, int *format_len);
#endif // FT_PRINTF_H
