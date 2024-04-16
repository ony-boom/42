/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:28:43 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/15 07:10:16 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

# define MAX_MODIFIER_COUNT 6
# define MY_INT_MIN (-2147483648)

typedef enum my_bool
{
	FALSE = 0,
	TRUE = 1
}								t_bool;

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
	PLUS = '+',
	DIGIT = 'n'
}								t_format_modifier;

typedef struct format_config_modifier
{
	int							len;
	int							value;
	t_format_modifier			modifier_specifier;
}								t_format_config_modifier;

typedef struct format_config
{
	int							len;
	int							modifiers_size;
	t_format_specifier			specifier;
	t_format_config_modifier	*modifiers;
}								t_format_config;

typedef struct pad
{
	int							count;
	int							original_value;
	char						padding_char;
	t_bool						from_right;
	t_bool						initialized;
}								t_pad;

typedef struct sign
{
	t_bool						show;
	char						positive_sign;
}								t_format_sign;

typedef struct hex_format
{
	t_bool						use_upper;
	t_bool						prefix_0x;
	t_bool						initialized;
}								t_hex_format;

typedef struct number_format
{
	long long					number;
	t_bool						is_zero;
	t_bool						is_unsigned;
	t_format_sign				sign;
	t_pad						zero_pad;
	t_pad						space_pad;
	t_hex_format				hex_format;
}								t_number_format;

t_bool							is_valid_format_specifier(char c);

t_bool							is_valid_format_modifier(char c);

t_bool							is_pad_modifier(t_format_modifier modifier,
									t_format_specifier specifier);

t_format_config					new_format_config(char *format);

int								ft_printf(const char *str, ...);

int								print_char(char c, t_format_config *config);

int								trim_format(char *format);
int								print_number(int n, t_format_config *config);
int								print_unsigned(unsigned int n,
									t_format_config *config);
int								print_hex(unsigned long int n, t_bool use_upper,
									t_format_config *config);
int								print_repeat(char c, int count);

#endif // FT_PRINTF_H
