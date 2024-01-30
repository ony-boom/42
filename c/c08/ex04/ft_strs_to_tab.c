/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:27:43 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/30 06:32:28 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	write_stock(struct s_stock_str *stock, int index, char *str)
{
	char	*str_copy;

	str_copy = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (str_copy == 0)
		return (0);
	ft_strcpy(str_copy, str);
	stock[index] = (struct s_stock_str){.str = str, .size = ft_strlen(str),
		.copy = str_copy};
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*stock;

	i = 0;
	stock = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (stock == NULL)
		return (0);
	while (i < ac)
	{
		if (!write_stock(stock, i, av[i]))
			return (0);
		i++;
	}
	stock[i] = (struct s_stock_str){.str = 0, .size = 0, .copy = 0};
	return (stock);
}
