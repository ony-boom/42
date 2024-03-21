/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:51:29 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/21 23:34:35 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	print_ptr(void *ptr, t_format_config config)
{
  config.has_config = TRUE;
  config.modifier_config.prepend_hex_prefix = TRUE;
  return print_hex((unsigned long int)ptr , FALSE, config);
}
