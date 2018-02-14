/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:17:11 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 15:11:48 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*undefined_conv(char c)
{
	ft_putstr("conversion character: `");
	ft_putchar(c);
	ft_putstr("` is undefined or invalid (or not implemented).\n");
	//exit(1);
	return (0);
}
