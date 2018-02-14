/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_pad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 09:03:10 by briviere          #+#    #+#             */
/*   Updated: 2018/02/14 17:34:13 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void		apply_flags_pad_precision(char **res, size_t *len, t_flags flags)
{
	if (flags.precision > 0 && (size_t)flags.precision > *len)
	{
		padding_left(res, (size_t)flags.precision - *len, '0');
		*len = flags.precision;
	}
}

void		apply_flags_pad_width(char **res, size_t len,
		t_flags flags, char s)
{
	if (flags.width >= 0 && (size_t)flags.width > len)
	{
		if ((flags.neg_field || !flags.zero_pad) && s)
			padding_left(res, 1, s);
		if (flags.neg_field)
			padding_right(res, (size_t)flags.width - len, ' ');
		else if (flags.zero_pad)
			padding_left(res, (size_t)flags.width - len, '0');
		else
			padding_left(res, (size_t)flags.width - len, ' ');
		if (flags.zero_pad && !flags.neg_field && s)
			padding_left(res, 1, s);
	}
	else if (s)
		padding_left(res, 1, s);
}

void		apply_flags_pad_int(char **res, size_t len, t_flags flags, char s)
{
	apply_flags_pad_precision(res, &len, flags);
	if (s)
		len++;
	apply_flags_pad_width(res, len, flags, s);
}

static void	apply_base(char **res, char base_chr)
{
	if (base_chr != '0')
	{
		padding_left(res, 2, '0');
		(*res)[1] = base_chr;
	}
	else
		padding_left(res, 1, '0');
}

void		apply_flags_pad_int_base(char **res, size_t len, t_flags flags,
		char base_chr)
{
	int		to_add;

	to_add = 2;
	if (base_chr == '0')
		to_add = 1;
	if (!flags.alter_form)
		return (apply_flags_pad_int(res, len, flags, 0));
	apply_flags_pad_precision(res, &len, flags);
	len += to_add;
	if (flags.zero_pad)
	{
		apply_flags_pad_width(res, len, flags, 0);
		apply_base(res, base_chr);
	}
	else
	{
		apply_base(res, base_chr);
		apply_flags_pad_width(res, len, flags, 0);
	}
}
