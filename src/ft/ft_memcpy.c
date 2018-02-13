/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:57:48 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 10:39:59 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		idx;
	char		*dst_ptr;
	const char	*src_ptr;

	idx = 0;
	dst_ptr = dst;
	src_ptr = src;
	while (idx < n)
	{
		dst_ptr[idx] = src_ptr[idx];
		idx++;
	}
	return (dst);
}
