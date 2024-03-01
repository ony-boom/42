#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/libft.h"

typedef enum {
  CHAR = 'c',
  STR = 's',
  POINTER = 'p',
  DECIMAL = 'd',
  INTEGER = 'i',
  UNSIGNED_INT = 'u',
  HEX = 'x',
  UPPER_HEX = 'X',
  PERCENT = '%'
} t_format;

int ft_printf(const char *format, ...);

#endif // FT_PRINTF_H
