/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:46:55 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 14:31:41 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	int		src_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= (unsigned int)src_len)
		return (ft_strdup(""));
	if (start + len > (unsigned int)src_len)
		len = src_len - start + 1;
	else
		len += 1;
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
