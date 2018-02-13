/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:30:05 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 12:28:31 by briviere         ###   ########.fr       */
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

static char		*apply_conv(char c, va_list *ap, t_flags flags)
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

static t_flags	read_flags(const char *format, size_t *idx, va_list *ap)
{
	t_flags		flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	flags.width = -1;
	flags.precision = -1;
	// TODO: split code
	// TODO: $
	while (is_flag(format[*idx]))
	{
		set_flag(&flags, format[*idx]);
		(*idx)++;
	}
	if (format[*idx] >= '0' && format[*idx] <= '9')
	{
		flags.width = ft_atoi(format + *idx);
		*idx += ft_numlen(flags.width);
	}
	if (format[*idx] == '.')
	{
		*idx += 1;
		if (format[*idx] == '*')
		{
			*idx += 1;
			flags.precision = va_arg(*ap, int);
		}
		else
		{
			flags.precision = ft_atoi(format + *idx);
			*idx += ft_numlen(flags.precision);
		}
	}
	if (is_flag_len(format[*idx]))
		*idx += set_flag_len(&flags, format + *idx);
	return (flags);
}

char			*do_conv(const char *format, size_t *idx, va_list *ap)
{
	char		*res;
	t_flags		flags;

	res = 0;
	flags = read_flags(format, idx, ap);
	if (format[*idx] == '%')
		res = ft_strdup("%");
	else
		res = apply_conv(format[*idx], ap, flags);
	(*idx)++;
	return (res);
}
