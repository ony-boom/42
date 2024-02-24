/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:10:32 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 10:32:54 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compare(char *a, char *b)
{
	while (*a && *b)
	{
		if (*a != *b)
		{
			return (0);
		}
		a++;
		b++;
	}
	return (*b == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!to_find[0])
		return (str);
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (0);
}