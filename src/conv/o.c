/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 09:28:13 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 18:25:24 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static unsigned long long	conv_o_cast(unsigned long long val, t_flag_len len)
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

char						*conv_o(va_list *ap, t_flags flags)
{
	char		*res;
	size_t		len;

	res = ft_lltoa_base(conv_o_cast(va_arg(*ap, unsigned long long),
				flags.len), "01234567");
	len = ft_strlen(res);
	if (res[0] == '0' && flags.precision == 0 && !flags.alter_form)
	{
		res[0] = 0;
		len = 0;
	}
	if (res[0] != '\0' && res[0] != '0')
		apply_flags_pad_int_base(&res, len, flags, '0');
	else
		apply_flags_pad_int(&res, len, flags, 0);
	return (res);
}
