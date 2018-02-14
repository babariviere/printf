/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:40:25 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 13:40:50 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_upper_d(va_list *ap, t_flags flags)
{
	flags.len = FLAG_L;
	return (conv_d(ap, flags));
}
