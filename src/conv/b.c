/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:35:27 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 14:35:54 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_b(va_list *ap, t_flags flags)
{
	char		*res;
	size_t		len;

	res = ft_lltoa_base(va_arg(*ap, unsigned long long), "01");
	len = ft_strlen(res);
	apply_flags_pad_int_base(&res, len, flags, 'b');
	return (res);
}
