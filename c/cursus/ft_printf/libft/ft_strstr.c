/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:33:18 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 15:09:55 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	if (!to_find[0])
		return (str);
	while (*str != '\0')
	{
		if ((*str == *to_find) && ft_strcmp(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
