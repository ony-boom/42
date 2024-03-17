/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:22:08 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/17 22:30:34 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	is_valid_char(char c, const char *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == c)
			return (TRUE);
	}
	return (FALSE);
}

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
