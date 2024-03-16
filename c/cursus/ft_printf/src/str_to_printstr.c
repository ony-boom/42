/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_printstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:25:01 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/16 10:57:39 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*str_to_printfstr(char *base_str)
{
	if (!base_str)
		return (ft_strdup("(null)"));
	return (ft_strdup(base_str));
}
