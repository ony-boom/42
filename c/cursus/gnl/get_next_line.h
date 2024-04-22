/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:01:41 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/21 10:10:25 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif // !BUFFER_SIZE

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
  char			*content;
  struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int ft_strlen(const char *str);
t_list	*ft_lstnew(void *content);
int get_line_len(t_list *list);
void	ft_lstadd_back(t_list **lst, t_list *new_l);

#endif // !GET_NEXT_LINE_H
