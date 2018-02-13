/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:10:33 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 14:21:04 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

size_t			ft_litoa_len_base(unsigned long int val, int base)
{
	size_t		len;

	if (val == 0)
		return (1);
	len = 0;
	while (val != 0)
	{
		val /= base;
		len += 1;
	}
	return (len);
}

static void		ft_litoa_rec_base(char *buf, unsigned long int val,
		size_t *idx, t_base base)
{
	if (val >= base.len)
		ft_litoa_rec_base(buf, val / base.len, idx, base);
	buf[*idx] = base.base[val % base.len];
	(*idx)++;
}

void			ft_litoa_base(unsigned long int val, char *buf, char *base)
{
	size_t		idx;

	idx = 0;
	ft_litoa_rec_base(buf, val, &idx, (t_base){base, ft_strlen(base)});
}
