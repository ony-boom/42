/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:29:01 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/26 22:57:38 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_l)
{
	t_list	*last;

	if (!new_l)
		return ;
	if (!(*lst))
	{
		*lst = new_l;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_l;
}
