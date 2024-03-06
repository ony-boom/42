/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:15:35 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/06 14:53:44 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef enum e_format
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
}							t_format_specifier;

typedef struct format_modifier
{
	unsigned int			left_pad;
	unsigned int			right_pad;
	unsigned int			zero_pad;
}							t_format_modifier;

typedef struct format
{
	t_format_modifier		*modifier;
	t_format_specifier		specifier;
}							t_format;

typedef char				*(*t_format_handler)(va_list params);

# define SPECIFER_LIST_SIZE 10

int							ft_printf(const char *str, ...);
int							get_hex(int n, int use_upper);
t_format					*get_format(const char *str, int *format_len);
t_format_modifier			*get_modifier(const char *str, int *modifier_len);
void						free_format(t_format *format);

char						*new_str_builder(t_format *format, va_list params);
const t_format_specifier	*get_specifier_list(void);

#endif // FT_PRINTF_H
