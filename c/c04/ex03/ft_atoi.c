/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:33:50 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/22 15:04:08 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*trim_start(char *str)
{
	while (*str && (*str == ' ' || *str == '0'))
		str++;
	return (str);
}

int	set_sign(char **input)
{
	int		count;
	char	*str;

	count = 0;
	str = *input;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			count++;
		str++;
	}
	*input = str;
	return (count % 2);
}

int	is_num(char c, int *c_as_int)
{
	int	as_int;
	int	is_ok;

	as_int = c - '0';
	is_ok = as_int >= 0 && as_int <= 9;
	if (is_ok)
		*c_as_int = as_int;
	return (is_ok);
}

int	ft_atoi(char *base_str)
{
	int		num;
	char	*str;
	int		str_n;
	int		is_negative;

	num = 0;
	str = trim_start(base_str);
	is_negative = set_sign(&str);
	if (!*str || !is_num(*str, &str_n))
		return (0);
	num = *str - '0';
	str++;
	while (is_num(*str, &str_n))
	{
		num *= 10;
		num += str_n;
		str++;
	}
	if (is_negative)
		num *= -1;
	return (num);
}
