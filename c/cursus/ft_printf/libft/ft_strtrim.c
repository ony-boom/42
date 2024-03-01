/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:52:42 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 15:25:31 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	to_trim(const char *set, char c);

char	*ft_strtrim(const char *s1, const char *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	while (to_trim(set, s1[start]))
		start++;
	while (to_trim(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - (start - 1)));
}

static int	to_trim(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
