/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:24:22 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 10:34:03 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int		ft_printf(const char *format, ...)
{
	//va_list		vl;
	t_buf		*buf;
	char		*tmp;
	size_t		idx;
	int			res;

	(void)format;
	buf = create_buf(1024);
	idx = 0;
	while (format[idx] != 0)
	{
		if (format[idx] == '%')
		{
			tmp = do_conv(format, &idx);
			buf_putstr(buf, tmp);
			free(tmp);
		}
		else
			buf_putc(buf, format[idx++]);
	}
	res = write(1, buf->data, buf->len);
	delete_buf(&buf);
	return (res);
}
