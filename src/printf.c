/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:24:22 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 10:50:55 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_buf		*buf;
	char		*tmp;
	size_t		idx;
	int			res;

	va_start(ap, format);
	buf = create_buf(1024);
	idx = 0;
	while (format[idx] != 0)
	{
		if (format[idx] == '%')
		{
			idx++;
			tmp = do_conv(format, &idx, &ap);
			buf_putstr(buf, tmp);
			free(tmp);
		}
		else
			buf_putc(buf, format[idx++]);
	}
	res = write(1, buf->data, buf->len);
	delete_buf(&buf);
	va_end(ap);
	return (res);
}
