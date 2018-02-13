/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:18:13 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 10:39:45 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	*ft_memalloc(size_t size)
{
	void	*dst;

	if ((dst = malloc(size)) == 0)
		return (0);
	ft_memset(dst, 0, size);
	return (dst);
}
