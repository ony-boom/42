/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:48:37 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/17 03:06:12 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	int diff;

	i = 0;
	diff = 0;
	while (i <= n) {
		diff += s1[i] - s2[i];
	   i++;	
	}
	return diff;
}
