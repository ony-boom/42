/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:31:58 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/29 13:03:28 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sep(char *sep_like, char *sep)
{
	while (*sep)
	{
		if (*sep_like != *sep)
			return (0);
		sep++;
		sep_like++;
	}
	return (1);
}

int	get_size(const char *strr, char *charset)
{
	int		size;
	char	*str;

	size = 0;
	str = (char *)strr;
	while (*str)
	{
		if (is_sep(str, charset))
		{
			str += ft_strlen(charset);
			size++;
			continue ;
		}
		str++;
	}
	size++;
	return (size);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(const char *str, char *charset)
{
	int		i;
	char	**strs;
	char	*m_str;
	char	*cp;
	int		curr_size;

	i = 0;
	m_str = (char *)str;
	cp = (char *)str;
	strs = malloc(sizeof(char *) * get_size(str, charset) + 1);
	while (*m_str)
	{
		if (is_sep(m_str, charset))
		{
			m_str += ft_strlen(charset);
			strs[i] = malloc(sizeof(char) * curr_size);
			ft_strncpy(strs[i], cp, curr_size);
			cp += curr_size + ft_strlen(charset);
			curr_size = 0;
			i++;
		}
		curr_size++;
		m_str++;
	}
	if (i < get_size(str, charset))
	{
		strs[i] = malloc(sizeof(char) * curr_size);
		ft_strncpy(strs[i], cp, curr_size);
	}
	strs[++i] = 0;
	return (strs);
}

int	main(void)
{
	char	**s;
	int		n;

	s = ft_split("", " ");
	n = 0;
	while (s[n] != NULL)
	{
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
