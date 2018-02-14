/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:30:05 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 18:21:45 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

const t_conv_fn	g_conv_fn[] = {
	{'s', conv_s},
	{'S', conv_upper_s},
	{'p', conv_p},
	{'d', conv_d},
	{'D', conv_upper_d},
	{'i', conv_d},
	{'o', conv_o},
	{'O', conv_upper_o},
	{'u', conv_u},
	{'U', conv_upper_u},
	{'x', conv_x},
	{'X', conv_upper_x},
	{'c', conv_c},
	{'C', conv_upper_c},
	{'b', conv_b},
};

static char		*apply_conv(char c, size_t *i, va_list *ap, t_flags flags)
{
	size_t	idx;

	idx = 0;
	while (idx < (sizeof(g_conv_fn) / sizeof(g_conv_fn[0])))
	{
		if (g_conv_fn[idx].conv == c && g_conv_fn[idx].fn)
		{
			*i += 1;
			return (g_conv_fn[idx].fn(ap, flags));
		}
		idx++;
	}
	return (0);
}

static int		read_arg_int(const char *format, size_t *idx, va_list *ap)
{
	int		prec;

	if (format[*idx] == '*')
	{
		*idx += 1;
		return (va_arg(*ap, int));
	}
	if (format[*idx] < '0' || format[*idx] > '9')
		return (0);
	prec = ft_atoi(format + *idx);
	*idx += ft_numlen(prec);
	return (prec);
}

static t_flags	read_flags(const char *format, size_t *idx, va_list *ap)
{
	t_flags		flags;

	ft_memset(&flags, 0, sizeof(t_flags));
	flags.width = -1;
	flags.precision = -1;
	while (is_flag(format[*idx]))
	{
		set_flag(&flags, format[*idx]);
		(*idx)++;
	}
	if ((format[*idx] >= '0' && format[*idx] <= '9') || format[*idx] == '*')
		flags.width = read_arg_int(format, idx, ap);
	if (format[*idx] == '.')
	{
		(*idx)++;
		flags.precision = read_arg_int(format, idx, ap);
		if (flags.precision > 0)
			flags.zero_pad = 0;
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
	{
		(*idx)++;
		res = ft_strdup("%");
		if (flags.width > 1 && flags.neg_field)
			padding_right(&res, flags.width - 1, ' ');
		else if (flags.width > 1 && flags.zero_pad)
			padding_left(&res, flags.width - 1, '0');
		else if (flags.width > 1)
			padding_left(&res, flags.width - 1, ' ');
		return (res);
	}
	res = apply_conv(format[*idx], idx, ap, flags);
	return (res);
}
