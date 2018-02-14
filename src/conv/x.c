/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:29:15 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 18:16:58 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static unsigned long long	conv_x_cast(unsigned long long val, t_flag_len len)
{
	unsigned long long	casted;

	if (len == FLAG_HH)
		casted = (unsigned char)val;
	else if (len == FLAG_H)
		casted = (unsigned short)val;
	else if (len == FLAG_NONE)
		casted = (unsigned int)val;
	else
		casted = val;
	return (casted);
}

char						*conv_x(va_list *ap, t_flags flags)
{
	char		*res;
	size_t		len;

	res = ft_lltoa_base(conv_x_cast(va_arg(*ap, unsigned long long),
				flags.len), "0123456789abcdef");
	len = ft_strlen(res);
	if (res[0] == '0' && flags.precision == 0)
	{
		res[0] = 0;
		len = 0;
	}
	if (res[0] != '\0' && res[0] != '0')
		apply_flags_pad_int_base(&res, len, flags, 'x');
	else
		apply_flags_pad_int(&res, len, flags, 0);
	return (res);
}
