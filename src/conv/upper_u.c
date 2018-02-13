/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:37:26 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 14:39:16 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char			*conv_upper_u(va_list *ap, t_flags flags)
{
	unsigned long int	val;
	size_t				len;
	char				*res;

	val = va_arg(*ap, unsigned long int);
	len = ft_litoa_len_base(val, 10);
	if ((res = ft_strnew(len)) == 0)
		return (0);
	ft_litoa_base(val, res, "0123456789");
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
