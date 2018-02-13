/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:46:26 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 14:05:33 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	padding_left(char **str, size_t len, char fw)
{
	char	*tmp;
	size_t	old_len;

	if (len == 0)
		return ;
	tmp = *str;
	old_len = ft_strlen(tmp);
	tmp = ft_realloc(tmp, old_len, len + old_len);
	tmp[len + old_len] = 0;
	ft_memmove(tmp + len, tmp, old_len);
	ft_memset(tmp, fw, len);
	*str = tmp;
}

void	padding_right(char **str, size_t len, char fw)
{
	char	*tmp;
	size_t	old_len;

	if (len == 0)
		return ;
	tmp = *str;
	old_len = ft_strlen(tmp);
	tmp = ft_realloc(tmp, old_len, len + old_len);
	tmp[len + old_len] = 0;
	ft_memset(tmp + old_len, fw, len);
	*str = tmp;
}
