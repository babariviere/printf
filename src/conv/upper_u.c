/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:37:26 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 13:40:13 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char			*conv_upper_u(va_list *ap, t_flags flags)
{
	flags.len = FLAG_L;
	return (conv_u(ap, flags));
}
