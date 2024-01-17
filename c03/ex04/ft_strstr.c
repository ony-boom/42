/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:10:32 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/17 04:42:33 by rony-lov         ###   ########.fr       */
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
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return ("\0");
}
