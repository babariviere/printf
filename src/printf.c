/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:24:22 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 13:40:14 by briviere         ###   ########.fr       */
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

	buf = create_buf(1024);
	idx = 0;
	va_start(ap, format);
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
	va_end(ap);
	res = write(1, buf->data, buf->len);
	delete_buf(&buf);
	return (res);
}
