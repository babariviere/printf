/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:21:41 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 14:32:27 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_upper_x(va_list *ap, t_flags flags)
{
	char	*res;
	size_t	len;
	int		val;
	size_t	idx;

	val = va_arg(*ap, int);
	len = ft_itoa_len_base(val, 16);
	if ((res = ft_strnew(len + (flags.alter_form ? 2 : 0))) == 0)
		return (0);
	idx = 0;
	if (flags.alter_form)
	{
		res[idx++] = '0';
		res[idx++] = 'X';
	}
	ft_itoa_base(val, res + idx, "0123456789ABCDEF");
	return (res);
}
