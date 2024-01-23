/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:15:48 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/23 18:23:32 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	powered;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	powered = nb;
	while (power > 1)
	{
		powered *= nb;
		power--;
	}
	return (powered);
}
