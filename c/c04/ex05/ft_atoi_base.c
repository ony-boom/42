/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:22:46 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/23 19:54:24 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if ((base[i] >= 7 && base[i] <= 13) || base[i] == ' ' || base[i] == '-'
			|| base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

int	is_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	trim_get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || str[*i] == '0' || (str[*i] >= 7 && str[*i] <= 13))
		*i += 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	nb;
	int	in_base;
	int	len;

	nb = 0;
	i = 0;
	len = get_base(base);
	if (len >= 2)
	{
		sign = trim_get_sign(str, &i);
		in_base = is_in_base(str[i], base);
		while (in_base != -1)
		{
			nb = (nb * len) + in_base;
			i++;
			in_base = is_in_base(str[i], base);
		}
		return (nb *= sign);
	}
	return (0);
}
