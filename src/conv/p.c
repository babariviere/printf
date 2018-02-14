/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:14:37 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 18:11:36 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_p(va_list *ap, t_flags flags)
{
	char	*res;
	size_t	len;

	res = ft_lltoa_base((unsigned long long)va_arg(*ap, void *),
				"0123456789abcdef");
	len = ft_strlen(res);
	flags.alter_form = 1;
	if (res[0] == '0' && flags.precision == 0)
	{
		free(res);
		res = ft_strdup("");
		len = 0;
	}
	apply_flags_pad_int_base(&res, len, flags, 'x');
	return (res);
}
