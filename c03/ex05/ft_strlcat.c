/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:45:32 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/17 05:30:10 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
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

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;
	unsigned int src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	
	if(dest_len == size) return (dest_len + src_len);

	if(src_len < size - dest_len)
	{
		ft_strncat(dest, src, size);	
	} else {
		ft_strncat(dest, src, dest_len - size - 1);
	}
	return dest_len + src_len;
}

int main()
{
	char *src = "source, test";
	char dest[7] = "short: ";

	ft_strlcat(dest, src, 7);

	printf("%s", dest);
}
