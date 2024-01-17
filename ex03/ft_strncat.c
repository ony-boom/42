/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 02:31:09 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/17 02:50:02 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return (i);    
}


char *ft_strncat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	int dest_len = ft_strlen(dest);

	i = 0;
	while(i < size && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	dest[dest_len + i] = '\0';

	return dest;
}
