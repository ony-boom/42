/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   challenge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:14:02 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/27 09:05:08 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const int	g_shift = 13;

int	get_base_char_code(char c)
{
	int	is_upper;

	is_upper = ft_isupper(c);
	if (is_upper)
		return ('A');
	return ('a');
}

char	shift_char(char c)
{
	int		base_char_code;
	char	shifted;

	if (!ft_isalpha(c))
		return (c);
	base_char_code = get_base_char_code(c);
	shifted = (c - base_char_code + g_shift) % 26 + base_char_code;
	return (shifted);
}

char	map_fn(unsigned int i, char c)
{
	(void)i;
	return (shift_char(c));
}

char	*solve(char *input)
{
	return (ft_strmapi(input, &map_fn));
}

int	main(void)
{
	char	*solved;

	const char input[] = "Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu\n\
pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe gur\n\
arkg pvepyr. Guvf punyyratr vf vaqvivqhny, gurer vf bayl n cevmr sbe\n\
bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal nqinagntrq\n\
crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur cevmr jvyy\n\
erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf:\n\
Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl hccre tenivgl ureb";
	solved = solve((char *)input);
	ft_putstr_fd(solved, 1);
	ft_putstr_fd("\n", 1);
}
