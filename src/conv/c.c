/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:02:00 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 18:20:57 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_c(va_list *ap, t_flags flags)
{
	char	*s;

	if (flags.len == FLAG_L)
		return (conv_upper_c(ap, flags));
	if ((s = ft_strnew(1)) == 0)
		return (0);
	s[0] = (char)va_arg(*ap, int);
	if (s[0] == 0)
		s[0] = -1;
	if (flags.width > 1 && flags.neg_field)
		padding_right(&s, flags.width - 1, ' ');
	else if (flags.width > 1 && flags.zero_pad)
		padding_left(&s, flags.width - 1, '0');
	else if (flags.width > 1)
		padding_left(&s, flags.width - 1, ' ');
	return (s);
}
