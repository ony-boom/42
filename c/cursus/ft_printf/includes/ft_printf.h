#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef enum
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

typedef void	(*print_fn)(va_list);

typedef struct
{
	t_format	format_specifier;
	print_fn	fn;
}				t_printer;

typedef t_printer printers[sizeof(t_format)];

t_printer		*Printer_new(t_format specifier, print_fn printer_fn);

const t_printer	**get_printers(void);
const t_printer	*get_printer_at_format(const t_printer **printers,
					t_format format);

int				ft_printf(const char *format, ...);

t_printer		*int_printer(void);
t_printer		*char_printer(void);

#endif // FT_PRINTF_H
