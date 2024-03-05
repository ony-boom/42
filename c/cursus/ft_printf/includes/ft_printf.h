/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:15:35 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 19:41:29 by rony-lov         ###   ########.fr       */
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
}				t_format;

# define PRINTER_LIST_SIZE 10

typedef int		(*t_print_fn)(va_list);

typedef struct s_printer
{
	t_format	format_specifier;
	t_print_fn	fn;
}				t_printer;

typedef struct format_config {
	t_format format;
	unsigned int min_width;
	unsigned int left_pad;
	unsigned int right_pad;
} t_format_config;

t_printer		*printer_new(t_format specifier, t_print_fn printer_fn);

t_printer		**init_printers(void);
void			register_printer(t_printer **registry, t_printer *printer);

t_printer		*get_printer_at_format(t_printer **printers, t_format format);

void			free_mem(t_printer **registry);

int				ft_printf(const char *format, ...);

t_printer		*int_printer(void);
t_printer		*char_printer(void);
t_printer		*str_printer(void);
t_printer		*decimal_printer(void);
t_printer		*unsignedint_printer(void);

int	get_hex(int n, int use_upper);
int				hex_base_printf(va_list params, int uppper);
t_printer		*hex_lower_printer(void);
t_printer		*hex_upper_printer(void);
t_printer		*percent_printer(void);
t_printer		*pointer_printer(void);

#endif // FT_PRINTF_H
