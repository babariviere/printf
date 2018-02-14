/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:37:39 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 13:39:40 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*conv_upper_o(va_list *ap, t_flags flags)
{
	flags.len = FLAG_L;
	return (conv_o(ap, flags));
}
