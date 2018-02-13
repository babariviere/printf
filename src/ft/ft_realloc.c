/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 09:12:59 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 13:47:50 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	*ft_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void	*dst;

	if (prev_size >= new_size)
		return (ptr);
	if ((dst = malloc(new_size)) == 0)
	{
		free(ptr);
		return (0);
	}
	ft_memcpy(dst, ptr, prev_size);
	free(ptr);
	return (dst);
}
