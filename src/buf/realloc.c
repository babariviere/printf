/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:44:51 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 09:46:52 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	buf_realloc(t_buf *buf, size_t new_size)
{
	void	*dst;

	if (buf->allocated >= new_size)
		return ;
	if ((dst = malloc(new_size)) == 0)
		return ;
	ft_memcpy(dst, buf->data, buf->allocated);
	free(buf->data);
	buf->data = dst;
	buf->allocated = new_size;
}
