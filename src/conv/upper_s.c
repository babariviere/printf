/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:06:15 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 15:50:41 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static size_t	wchar_len_char(wchar_t *s)
{
	size_t		len;
	size_t		idx;

	len = 0;
	idx = 0;
	while (s[idx])
	{
		if (s[idx] <= 0x7f)
			len += 1;
		else if (s[idx] <= 0x7ff)
			len += 2;
		else if (s[idx] <= 0x7fff)
			len += 3;
		else
			len += 4;
		idx++;
	}
	return (len);
}

int				size_wchar(wchar_t uni)
{
	if (uni <= 0x7f)
		return (1);
	else if (uni <= 0x7ff)
		return (2);
	else if (uni <= 0xffff)
		return (3);
	return (4);
}

char			*conv_upper_s(va_list *ap, t_flags flags)
{
	wchar_t		*str;
	char		*res;
	size_t		len;
	size_t		idx;
	size_t		sidx;

	(void)flags;
	str = va_arg(*ap, wchar_t *);
	if (str == 0)
		return (ft_strdup("(null)"));
	if (flags.precision >= 0)
		len = flags.precision;
	else
		len = wchar_len_char(str);
	if ((res = ft_strnew(len)) == 0)
		return (0);
	sidx = 0;
	idx = 0;
	while ((sidx + size_wchar(str[idx]) - 1) < len)
		sidx += ft_wcharcpy(res + sidx, str[idx++]);
	if (flags.width >= 0 && len < (size_t)flags.width && flags.neg_field)
		padding_right(&res, flags.width - len, ' ');
	else if (flags.width >= 0 && len < (size_t)flags.width)
		padding_left(&res, flags.width - len, ' ');
	return (res);
}
