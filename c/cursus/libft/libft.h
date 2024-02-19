/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:28:25 by username          #+#    #+#             */
/*   Updated: 2024/02/19 15:01:02 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

int ft_isinrange(int n, int min, int max);
int ft_isupper(int c);
int ft_islower(int c);
int ft_isdigit(int c);
int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isprint(int c);
int ft_strlen(char *str);
void *ft_memset(void *s, int c, int n);
void ft_bzero(void *s, int n);
void *ft_memcpy(void *dest, const void *src, int n);

#endif // LIBFT_H
