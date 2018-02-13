/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:39:23 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 09:40:53 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	buf_putc(t_buf *buf, char c)
{
	if (buf->allocated <= (buf->len + 1))
		buf_realloc(buf, buf->allocated * 2);
	buf->data[buf->len++] = c;
}
