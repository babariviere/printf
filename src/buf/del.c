/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:38:15 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 09:39:04 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void		delete_buf(t_buf **buf)
{
	if (buf == 0)
		return ;
	free((*buf)->data);
	free(*buf);
	*buf = 0;
}
