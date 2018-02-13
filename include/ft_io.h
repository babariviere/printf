/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:25:03 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 09:19:13 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stdarg.h>
# include <unistd.h>

typedef enum	e_flag_len {
	FLAG_HH,
	FLAG_H,
	FLAG_L,
	FLAG_LL,
	FLAG_J,
	FLAG_Z,
	FLAG_NONE,
}				t_flag_len;

typedef struct	s_flags {
	char		alter_form : 1;
	char		zero_pad : 1;
	char		neg_field : 1;
	char		blank_pos : 1;
	char		sign : 1;
	char		precision;
	char		min_width;
	t_flag_len	len;
}				t_flags;

typedef struct	s_conv_fn {
	char	conv;
	char	*(*fn)(void *elem, t_flags flags);
}				t_conv_fn;

char	*undefined_conv(void *elem, t_flags flags);

//SpdDioOuUxXcC
const t_conv_fn	g_conv_fn[] = {
	{'s', 0},
	{'S', 0},
	{'p', 0},
	{'d', 0},
	{'D', 0},
	{'i', 0},
	{'o', 0},
	{'O', 0},
	{'u', 0},
	{'U', 0},
	{'x', 0},
	{'X', 0},
	{'c', 0},
	{'C', 0},
	{'b', 0},
	{0, undefined_conv},
};

size_t	ft_strlen(char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		printf(const char *format, ...);

#endif
