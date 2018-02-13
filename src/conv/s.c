/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:04:00 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 12:28:58 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_s(va_list *ap, t_flags flags)
{
	if (flags.len == FLAG_L)
		return (conv_upper_s(ap, flags));
	if (flags.precision >= 0)
		return (ft_strndup(va_arg(*ap, char *), flags.precision));
	return (ft_strdup(va_arg(*ap, char *)));
}