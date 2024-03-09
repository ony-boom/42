/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_printstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:25:01 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/09 08:51:34 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*str_to_printfstr(va_list params)
{
	char	*str;

	str = va_arg(params, char *);
	if (!str || !*str)
	{
		if (!str)
			return ("null");
		return (0);
	}
	return (str);
}
