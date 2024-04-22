/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:00:46 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/19 08:11:19 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*new;

	len = ft_strlen(src);
	new = malloc((len + 1) * sizeof(char));
	if (new == 0)
		return (0);
	ft_strlcpy(new, src, len + 1);
	return (new);
}
