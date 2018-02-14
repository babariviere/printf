/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:04:00 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 18:22:37 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_s(va_list *ap, t_flags flags)
{
	char	*s;
	size_t	len;

	if (flags.len == FLAG_L)
		return (conv_upper_s(ap, flags));
	s = va_arg(*ap, char *);
	if (s == 0 && flags.width <= 0)
		return (ft_strdup("(null)"));
	if (flags.precision >= 0)
		s = ft_strndup(s, flags.precision);
	else
		s = ft_strdup(s);
	len = ft_strlen(s);
	if (flags.width >= 0 && len < (size_t)flags.width && flags.neg_field)
		padding_right(&s, flags.width - len, ' ');
	else if (flags.width >= 0 && len < (size_t)flags.width && flags.zero_pad)
		padding_left(&s, flags.width - len, '0');
	else if (flags.width >= 0 && len < (size_t)flags.width)
		padding_left(&s, flags.width - len, ' ');
	return (s);
}
