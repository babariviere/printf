/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:05:51 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 17:51:57 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_upper_c(va_list *ap, t_flags flags)
{
	char	*s;
	size_t	len;

	if ((s = ft_strnew(4)) == 0)
		return (0);
	ft_wcharcpy(s, va_arg(*ap, wchar_t));
	if (s[0] == 0)
		s[0] = -1;
	len = ft_strlen(s);
	if (flags.width > (int)len)
		padding_left(&s, flags.width - len, ' ');
	return (s);
}
