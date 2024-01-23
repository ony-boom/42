/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:40:15 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/23 22:59:03 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	diff;
	int	sqrt;

	i = 0;
	sqrt = 0;
	diff = nb;
	while (diff != 0)
	{
		if (i > nb)
			return (0);
		if (i % 2)
		{
			diff -= i;
			sqrt++;
		}
		i++;
	}
	return (sqrt);
}
