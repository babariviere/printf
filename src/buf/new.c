/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:35:33 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 09:36:51 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

t_buf		*create_buf(size_t to_allocate)
{
	t_buf	*res;

	if ((res = ft_memalloc(sizeof(t_buf))) == 0)
		return (0);
	if ((res->data = ft_memalloc(sizeof(char *) * to_allocate)) == 0)
	{
		free(res);
		return (0);
	}
	res->allocated = to_allocate;
	res->len = 0;
	return (res);
}
