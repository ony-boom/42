/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:24:12 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/27 17:32:22 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (power(nb, power - 1) * nb);
}
