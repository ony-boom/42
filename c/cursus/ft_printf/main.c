/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:22:16 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/03 20:50:48 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	int		age;
	char	*src;
	char	*str;
	int		len;
	int		o_len;
	char	*str2;

	str = "Here is as decimal example => ";
	str2 = "\0";
	src = "%cny is my name, and i'm %i years old, cool hein. %s %d, next is %%,\
		and last is pointer %p, nice i guess";
	c = 'o';
	age = 21;
	printf("yours: \n");
	len = ft_printf(src, c, age, str, 38, &str2);
	printf("\n");
	printf("original: \n");
	o_len = printf(src, c, age, str, 38, &str2);
	printf("\n");
	printf("yours is printing: %u char\n", len);
	printf("original is: %d char\n", o_len);
}
