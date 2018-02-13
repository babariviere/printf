/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:37:26 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 14:00:37 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static size_t	ft_ulitoa_len(unsigned long int val)
{
	size_t		len;

	if (val == 0)
		return (1);
	len = 0;
	while (val != 0)
	{
		val /= 10;
		len += 1;
	}
	return (len);
}

static void		ft_ulitoa_rec(char *buf, unsigned long int val, size_t *idx)
{
	if (val == 0)
		return ;
	if (val >= 10)
		ft_ulitoa_rec(buf, val / 10, idx);
	buf[*idx] = val % 10 + '0';
	(*idx)++;
}

static void		ft_ulitoa(unsigned long int val, char *buf)
{
	size_t		idx;

	idx = 0;
	ft_ulitoa_rec(buf, val, &idx);
}

char			*conv_upper_u(va_list *ap, t_flags flags)
{
	unsigned long int	val;
	size_t				len;
	char				*res;

	val = va_arg(*ap, unsigned long int);
	len = ft_ulitoa_len(val);
	if ((res = ft_strnew(len)) == 0)
		return (0);
	ft_ulitoa(val, res);
	if (flags.precision >= 0 && flags.precision > (int)len)
		padding_left(&res, (size_t)flags.precision - len, '0');
	else if (flags.width >= 0 && flags.width > (int)len)
	{
		if (flags.neg_field)
			padding_right(&res, (size_t)flags.width - len, ' ');
		else if (flags.zero_pad)
			padding_left(&res, (size_t)flags.width - len, '0');
		else
			padding_left(&res, (size_t)flags.width - len, ' ');
	}
	return (res);
}
