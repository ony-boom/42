/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_repeat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:33:11 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/09 22:36:23 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_repeat(char c, int reapeat)
{
	char	*str;

	str = ft_calloc(reapeat + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (reapeat)
	{
		*str++ = c;
		reapeat--;
	}
	return (str);
}
