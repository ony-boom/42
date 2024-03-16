/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:15:35 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/16 16:18:21 by rony-lov         ###   ########.fr       */
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

# define NOT_FOUND_SPECIFIER '!'

typedef struct s_pad_conf
{
	int						len;
	int						is_right;
	int						with_zero;
}							t_pad_conf;

typedef struct format_modifier
{
	t_pad_conf				pad;
}							t_format_modifier;

typedef struct format
{
	t_format_modifier		modifier;
	t_format_specifier		specifier;
}							t_format;

typedef struct s_builded_str
{
	int params_len;
	char *str;
} t_builded_str;

# define SPECIFER_LIST_SIZE 10

int							ft_printf(const char *str, ...);
int							get_hex(int n, int use_upper);
t_format					get_format(const char *str, int *format_len);
t_format_modifier			get_modifier(const char *str);

t_pad_conf					get_pad_conf(const char *str);

char						*hex_to_str(unsigned int n, int use_upper);

char						*unsigned_to_str(unsigned int n);
char						*pointer_to_str(void *pointer_like);
char						*str_to_printfstr(char *base_str);

char						*char_to_str(char c);
t_builded_str		new_str_builder(t_format format, va_list params);
const t_format_specifier	*get_specifier_list(void);

#endif // FT_PRINTF_H
