/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:41:00 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 16:04:00 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	buf_putstr(t_buf *buf, char *s)
{
	size_t		len;

	if (s == 0)
		return ;
	len = 0;
	while (s[len])
	{
		if (s[len] == -1)
			s[len] = 0;
		len++;
	}
	while (buf->allocated <= (buf->len + len))
		buf_realloc(buf, buf->allocated * 2);
	ft_strncpy(buf->data + buf->len, s, len);
	buf->len += len;
}
