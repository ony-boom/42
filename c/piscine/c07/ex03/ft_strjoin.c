/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:42 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/29 20:09:29 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src != '\0')
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = '\0';
	return (dest);
}

int	concatenate(char *str, int position, char *src)
{
	ft_strcpy(str + position, src);
	return (ft_strlen(src));
}

int	get_len(char **strs, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		sep_len;
	int		str_size;
	int		index;

	if (size <= 0)
	{
		str = (char *)malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	sep_len = ft_strlen(sep);
	str_size = get_len(strs, size) + (sep_len * (size - 1)) + 1;
	str = malloc(sizeof(char) * str_size);
	i = 0;
	index = 0;
	while (i < size)
	{
		index += concatenate(str, index, strs[i]);
		if (i < size - 1)
			index += concatenate(str, index, sep);
		i++;
	}
	return (str);
}
