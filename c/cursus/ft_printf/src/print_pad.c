/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:45:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/22 00:06:29 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_pad(t_print_pad_params params, int (*printer)(void *))
{
	int	printed;

	printed = 0;
	if (params.is_right)
	{
		printed += printer(params.rest);
		printed += print_repeat(params.padding_char, params.padding_count);
	}
	else
	{
		printed += print_repeat(params.padding_char, params.padding_count);
		printed += printer(params.rest);
	}
	return (printed);
}
