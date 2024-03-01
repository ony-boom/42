/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:42:04 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 12:32:08 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	char	*haystack;
	char	*needle;
	int		needle_len;

	haystack = (char *)big;
	needle = (char *)little;
	if (!*needle)
		return (haystack);
	if (len < 0)
		len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && (needle_len <= len))
	{
		if (*haystack == *needle && (ft_strncmp(haystack, needle,
					needle_len) == 0))
			return (haystack);
		haystack++;
		len--;
	}
	return (0);
}
