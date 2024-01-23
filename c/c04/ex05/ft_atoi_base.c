/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:43:28 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/22 15:24:54 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_char_in_base(char c, char *base)
{
	while (*base != '\0')
	{
		if (*base == c)
		{
			return (1); // Character is in the base
		}
		base++;
	}
	return (0); // Character is not in the base
}

int	ft_get_char_index(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0' && base[index] != c)
	{
		index++;
	}
	return ((base[index] == '\0') ? -1 : index);
}

int	ft_pow(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	str_len;
	int	i;
	int	base_size;
	int	digit_value;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	str_len = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	i = str_len - 1;
	base_size = 0;
	while (base[base_size] != '\0')
	{
		base_size++;
	}
	while (i >= 0)
	{
		if (!ft_char_in_base(str[i], base))
		{
			return (0); // Invalid character in the string
		}
		digit_value = ft_get_char_index(str[i], base);
		result += digit_value * ft_pow(base_size, str_len - 1 - i);
		i--;
	}
	return (result * sign);
}

int main() {
    char str[] = "42"; // Replace with your desired string
    char base[] = "01";   // Replace with your desired base

    int result = ft_atoi_base(str, base);

    printf("Decimal representation of %s in base %s: %d\n", str, base, result);

    return 0;
}
