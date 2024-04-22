/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:03:01 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/21 14:05:35 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	list_has_line(t_list *list)
{
	char	*str;
	int		i;

	if (!list)
		return (0);
	while (list)
	{
		str = list->content;
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	fill_list(t_list **list, int fd)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	while (!list_has_line(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (read_bytes);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		printf("read_bytes: %d\n", read_bytes);
		if (read_bytes <= 0)
		{
			// TODO: properly free the list
			free(*list);
			*list = NULL;
			free(buffer);
			return (read_bytes);
		}
		buffer[read_bytes] = '\0';
		ft_lstadd_back(list, ft_lstnew(buffer));
	}
	return (read_bytes);
}

void	*fill_line(t_list *list, char *line)
{
	int	i;
	int	found_line;

	i = 0;
	found_line = 0;
	while (list)
	{
		while (*(list->content))
		{
			if (*(list->content) == '\n')
			{
				found_line = 1;
				break ;
			}
			line[i++] = *(list->content);
			list->content++;
		}
		list->content += found_line;
		list = list->next;
	}
	return (line);
}

char	*build_line(t_list *list)
{
	int		size;
	char	*line;

	if (!list)
		return (NULL);
	size = get_line_len(list);
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	line = fill_line(list, line);
	line[size] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	int				ok;
	static t_list	*list = NULL;

	ok = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ok = fill_list(&list, fd) > 0;
	if (!list || !ok)
	{
		// TODO: properly free the list
		free(list);
		list = NULL;
		return (NULL);
	}
	line = build_line(list);
	return (line);
}
