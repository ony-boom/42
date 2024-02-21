/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:52:50 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/21 15:43:26 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	lower;

	lower = c;
	if (!ft_isupper(c))
		return (lower);
	lower = c - 'A' + 'a';
	if (!ft_isalpha(lower))
		return (c);
	return (lower);
}
