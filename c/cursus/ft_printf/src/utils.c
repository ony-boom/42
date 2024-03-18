/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:22:08 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/18 07:43:07 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_hex(int n, int use_upper)
{
	char	c;

	if (n < 10)
		return ('0' + n);
	else
	{
		c = 'a';
		if (use_upper)
			c = 'A';
		return (c + n - 10);
	}
}
