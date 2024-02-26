/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:29:16 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/25 19:19:18 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c);
static char	*get_first(char **str, char c);
static char	*trim_c_start(const char *str, char c);
static void	free_memory(char **strs, int count);

char	**ft_split(const char *s, char c)
{
	int		i;
	int		len;
	char	**strs;

	i = 0;
	len = word_count(s, c) + 1;
	strs = ft_calloc(len, sizeof(char *));
	if (!strs)
		return (NULL);
	while (i < len - 1)
	{
		strs[i] = get_first((char **)&s, c);
		if (!strs[i])
		{
			free_memory(strs, i);
			return (NULL);
		}
		i++;
	}
	return (strs);
}

static void	free_memory(char **strs, int count)
{
	while (count >= 0)
		free(strs[count--]);
	free(strs);
}

static int	word_count(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
		{
			str++;
			continue ;
		}
		while (*str && *str != c)
			str++;
		count++;
	}
	return (count);
}

static char	*get_first(char **str, char c)
{
	int		w_len;
	char	*trimmed;

	w_len = 0;
	trimmed = trim_c_start(*str, c);
	while (trimmed[w_len] && trimmed[w_len] != c)
		w_len++;
	*str = trimmed + w_len + 1;
	return (ft_substr(trimmed, 0, w_len));
}

static char	*trim_c_start(const char *str, char c)
{
	while (*str && *str == c)
		str++;
	return ((char *)(str));
}
