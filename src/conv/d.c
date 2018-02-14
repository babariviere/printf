/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:52:59 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 18:17:35 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static unsigned long long	conv_d_cast(long long val, t_flag_len len, int *neg)
{
	unsigned long long	casted;

	*neg = 1;
	casted = val;
	if (len == FLAG_HH && (char)val < 0)
		casted = (unsigned char)-(unsigned char)val;
	else if (len == FLAG_H && (short)val < 0)
		casted = (unsigned short)-(unsigned short)val;
	else if (len == FLAG_NONE && (int)val < 0)
		casted = (unsigned int)-(unsigned int)val;
	else if (len == FLAG_L && (long)val < 0)
		casted = (unsigned long)-(unsigned long)val;
	else if (len != FLAG_HH && len != FLAG_H && len != FLAG_NONE && val < 0)
		casted = -(unsigned long long)val;
	else
	{
		*neg = 0;
		if (len == FLAG_HH)
			casted = (unsigned char)val;
		else if (len == FLAG_H)
			casted = (unsigned short)val;
		else if (len == FLAG_NONE)
			casted = (unsigned int)val;
	}
	return (casted);
}

char						*conv_d(va_list *ap, t_flags flags)
{
	long long			val;
	size_t				len;
	char				*res;
	int					neg;

	if (flags.len == FLAG_HH || flags.len == FLAG_H || flags.len == FLAG_NONE)
		val = va_arg(*ap, int);
	else
		val = va_arg(*ap, long long);
	res = ft_lltoa_base(conv_d_cast(val, flags.len, &neg), "0123456789");
	len = ft_strlen(res);
	if (res[0] == '0' && flags.precision == 0)
	{
		res[0] = 0;
		len = 0;
	}
	if (neg)
		apply_flags_pad_int(&res, len, flags, '-');
	else if (flags.sign)
		apply_flags_pad_int(&res, len, flags, '+');
	else if (flags.blank_pos)
		apply_flags_pad_int(&res, len, flags, ' ');
	else
		apply_flags_pad_int(&res, len, flags, 0);
	return (res);
}
