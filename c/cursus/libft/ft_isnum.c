/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:32:07 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 11:32:24 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char c, int *c_as_int)
{
	int	as_int;
	int	is_ok;

	as_int = c - '0';
	is_ok = as_int >= 0 && as_int <= 9;
	if (is_ok)
		*c_as_int = as_int;
	return (is_ok);
}
