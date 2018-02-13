/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:37:26 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 13:39:57 by briviere         ###   ########.fr       */
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

static void		ft_ulitoa_rec(char *buf, unsigned long int val, size_t idx)
{
	if (val == 0)
		return ;
	buf[idx] = val % 10 + '0';
	ft_ulitoa_rec(buf, val / 10, idx - 1);
}

static char		*ft_ulitoa(unsigned long int val, size_t len, char fill_with)
{
	char	*res;

	if ((res = ft_strnew(len)) == 0)
		return (0);
	ft_memset(res, fill_with, len);
	ft_ulitoa_rec(res, val, len - 1);
	return (res);
}

char			*conv_upper_u(va_list *ap, t_flags flags)
{
	unsigned long int	val;
	size_t				len;
	char				*tmp;

	val = va_arg(*ap, unsigned long int);
	len = ft_ulitoa_len(val);
	if (flags.precision >= 0 && (int)len < flags.precision)
		return (ft_ulitoa(val, flags.precision, '0'));
	if (flags.width >= 0 && (int)len < flags.width)
	{
		if (flags.neg_field)
			return (ft_ulitoa(val, flags.width, ' '));
		if (flags.zero_pad && !flags.neg_field)
			return (ft_ulitoa(val, flags.width, '0'));
		if (!flags.zero_pad)
			return (ft_ulitoa(val, flags.width, ' '));
		return (ft_ulitoa(val, flags.width, ' '));
	}
	return (ft_ulitoa(val, len, 0));
}
