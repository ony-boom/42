/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:22:16 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/16 17:10:42 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

// TODO: fix char printer on 0
int	main(void)
{
	char *str = " %-1c %-1c %-3c \n";
	
	ft_printf(str, '0', 0, '1');
	printf(str, '0', 0, '1');
}
