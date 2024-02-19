/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:41:06 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/27 20:23:52 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_base(const char *base);
int		trim_get_sign(const char *str, int *i);
int		is_in_base(char str, const char *base);
void	ft_rev_int_tab(char *tab, int size);

int	nbrlen(const char *str, const char *base)
{
	int	i;

	i = 0;
	while (str[i] && is_in_base(str[i], base) != -1)
		i++;
	return (i);
}

int	power(int nb, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	if (p == 1)
		return (nb);
	return (power(nb, p - 1) * nb);
}

int	to_base_ten(const char *nbr, int int_base, const char *base)
{
	int	i;
	int	nb;
	int	len;
	int	sign;

	nb = 0;
	i = 0;
	len = nbrlen(nbr, base) - 1;
	sign = trim_get_sign(nbr, &i);
	len -= i;
	while (len >= 0)
	{
		nb += is_in_base(nbr[i], base) * power(int_base, len);
		i++;
		len--;
	}
	return (nb *= sign);
}

char	*to_given_base(int base_10_int, int to_base, const char *base)
{
	int				i;
	char			*converted;
	unsigned int	nb;

	i = 0;
	nb = base_10_int;
	converted = malloc((sizeof(int) * 32));
	if (base_10_int < 0)
		i = 1;
	while (nb != 0)
	{
		converted[i] = base[(nb % to_base)];
		nb /= to_base;
		i++;
	}
	if (base_10_int < 0)
		converted[i++] = '-';
	converted[i] = '\0';
	ft_rev_int_tab(converted, i);
	return (converted);
}

/*
* Refefence:
* https://byjus.com/gate/conversion-of-bases-to-other-bases-notes.
*/

char	*ft_convert_base(const char *nbr, const char *base_from,
		const char *base_to)
{
	int		from_base;
	int		to_base;
	int		as_base_10;
	char	*zero;

	from_base = get_base(base_from);
	to_base = get_base(base_to);
	if (nbr[0] == '0' && !nbr[1])
	{
		zero = malloc(sizeof(char));
		zero[0] = '0';
		return (zero);
	}
	if (from_base < 2 || to_base < 2)
		return (0);
	as_base_10 = to_base_ten(nbr, from_base, base_from);
	return (to_given_base(as_base_10, to_base, base_to));
}
