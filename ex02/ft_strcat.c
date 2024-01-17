/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 01:29:05 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/17 02:27:40 by rony-lov         ###   ########.fr       */
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

char *ft_strcat(char *dest, char *src)
{
    int i;
    int dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	
	while(src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	
	dest[dest_len + i] = '\0';
	
	return (dest);
}
