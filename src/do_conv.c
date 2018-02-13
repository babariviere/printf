/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:30:05 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 11:55:28 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

const t_conv_fn	g_conv_fn[] = {
	{'s', conv_s},
	{'S', conv_upper_s},
	{'p', 0},
	{'d', 0},
	{'D', 0},
	{'i', 0},
	{'o', 0},
	{'O', 0},
	{'u', 0},
	{'U', 0},
	{'x', 0},
	{'X', 0},
	{'c', 0},
	{'C', 0},
	{'b', 0},
};

static char	*apply_conv(char c, va_list *ap, t_flags flags)
{
	size_t	idx;

	idx = 0;
	while (idx < (sizeof(g_conv_fn) / sizeof(g_conv_fn[0])))
	{
		if (g_conv_fn[idx].conv == c && g_conv_fn[idx].fn)
			return (g_conv_fn[idx].fn(ap, flags));
		else if (g_conv_fn[idx].conv == c)
			break ;
		idx++;
	}
	return (undefined_conv(c));
}

char		*do_conv(const char *format, size_t *idx, va_list *ap)
{
	char		*res;

	res = 0;
	if (format[*idx] == '%')
		res = ft_strdup("%");
	else
		res = apply_conv(format[*idx], ap, (t_flags){0, 0,0,0,0,0,0,0});
	(*idx)++;
	return (res);
}
