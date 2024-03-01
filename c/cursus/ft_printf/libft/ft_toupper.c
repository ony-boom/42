/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:52:50 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 12:04:45 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	upper;

	upper = c;
	if (!ft_islower(c))
		return (c);
	upper = c - 'a' + 'A';
	if (!ft_isalpha(upper))
		return (c);
	return (upper);
}
