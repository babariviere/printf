/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:38:38 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 10:40:09 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	idx;

	idx = 0;
	while (src[idx] && idx < len)
	{
		dst[idx] = src[idx];
		idx++;
	}
	while (idx < len)
		dst[idx++] = 0;
	return (dst);
}
