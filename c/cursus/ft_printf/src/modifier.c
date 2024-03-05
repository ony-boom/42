/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:43:41 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 22:44:59 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int	*get_pad(const char *str)
{
	int			pad;
	int			is_right;
	int			substr_end;
	static int	pad_conf[2];

	pad = 0;
	substr_end = 0;
	is_right = *str == '-';
	if (is_right)
		str++;
	while (ft_isdigit(*str))
	{
		substr_end++;
		str++;
	}
	pad = ft_atoi(ft_substr(str, 0, substr_end));
	pad_conf[0] = pad;
	pad_conf[1] = 0;
	if (is_right)
	{
		pad_conf[0] = 0;
		pad_conf[1] = pad;
	}
	return (pad_conf);
}

int	get_zero_pad(const char *str)
{
	int	pad;
	int	substr_end;

	pad = 0;
	substr_end = 0;
	while (ft_isdigit(*str))
	{
		substr_end++;
		str++;
	}
	return (ft_atoi(ft_substr(str, 0, substr_end)));
}

t_format_modifier	*get_modifier(const char *str)
{
	t_format_modifier	*modifier;

	modifier = ft_calloc(sizeof(t_format_modifier), 1);
	if (!modifier)
		return (NULL);

	modifier->left_pad = get_pad(str)[0];
	modifier->right_pad = get_pad(str)[1];
	modifier->zero_pad = get_zero_pad(str);
	return (modifier);
}
