/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:25:03 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 11:55:15 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stdarg.h>
# include <stdlib.h>
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
	char		width;
	char		precision;
	t_flag_len	len;
}				t_flags;

typedef struct	s_conv_fn {
	char	conv;
	char	*(*fn)(va_list *ap, t_flags flags);
}				t_conv_fn;

char			*conv_s(va_list *ap, t_flags flags);
char			*conv_upper_s(va_list *ap, t_flags flags);

char			*undefined_conv(char c);


char			*ft_strnew(size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
int				ft_putchar(char c);
int				ft_putstr(char *s);
char			*ft_strncpy(char *dst, const char *src, size_t n);

void			*ft_memset(void *ptr, int c, size_t size);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t size);

typedef struct	s_buf {
	char	*data;
	size_t	len;
	size_t	allocated;
}				t_buf;

t_buf			*create_buf(size_t to_allocate);
void			buf_putc(t_buf *buf, char c);
void			buf_putstr(t_buf *buf, char *s);
void			buf_realloc(t_buf *buf, size_t new_size);
void			delete_buf(t_buf **buf);

char			*do_conv(const char *format, size_t *idx, va_list *ap);


#endif
