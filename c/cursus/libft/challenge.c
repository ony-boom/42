/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   challenge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:14:02 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/28 10:22:34 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	get_base_char_code(char c)
{
	int	is_upper;

	is_upper = ft_isupper(c);
	if (is_upper)
		return ('A');
	return ('a');
}

char	shift_char(char c, int shift)
{
	int		base_char_code;
	char	shifted;

	if (!ft_isalpha(c))
		return (c);
	base_char_code = get_base_char_code(c);
	shifted = (c - base_char_code + shift) % 26 + base_char_code;
	return (shifted);
}

int	main(void)
{
	FILE	*ptr;
	char	ch;
	int		shift;

	ptr = fopen("input.txt", "r");
	shift = 13;
	if (ptr == NULL)
	{
		ft_putstr_fd("Can't read input file\n", 1);
		return (1);
	}
	ch = fgetc(ptr);
	while (ch != EOF)
	{
		ft_putchar_fd(shift_char(ch, shift), 1);
		ch = fgetc(ptr);
	}
	fclose(ptr);
	return (0);
}
