/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:04:34 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/03 21:26:54 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	free_mem(t_printer **registry)
{
	t_printer	**current;

	if (!registry || !*registry)
		return ;
	current = registry;
	while (*current)
	{
		free(*current);
		++current;
	}
	free(registry);
}
