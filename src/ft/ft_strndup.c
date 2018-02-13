/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:57:12 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 12:21:47 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*ft_strndup(const char *s, size_t size)
{
	char	*res;
	size_t	idx;

	if ((res = ft_strnew(size)) == 0)
		return (0);
	idx = 0;
	while (idx < size)
	{
		res[idx] = s[idx];
		idx++;
	}
	return (res);
}
