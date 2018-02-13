/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:25:03 by briviere          #+#    #+#             */
/*   Updated: 2018/02/13 13:18:11 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum	e_flag_len {
	FLAG_NONE = 0,
	FLAG_HH,
	FLAG_H,
	FLAG_L,
	FLAG_LL,
	FLAG_J,
	FLAG_Z,
}				t_flag_len;

typedef struct	s_flags {
	int			alter_form : 1;
	int			zero_pad : 1;
	int			neg_field : 1;
	int			blank_pos : 1;
	int			sign : 1;
	int			width;
	int			precision;
	t_flag_len	len;
}				t_flags;

int			is_flag(char c);
void		set_flag(t_flags *flags, char c);
int			is_flag_len(char c);
int			set_flag_len(t_flags *flags, const char *s);

typedef struct	s_conv_fn {
	char	conv;
	char	*(*fn)(va_list *ap, t_flags flags);
}				t_conv_fn;

char			*conv_s(va_list *ap, t_flags flags);
char			*conv_upper_s(va_list *ap, t_flags flags);
char			*conv_upper_u(va_list *ap, t_flags flags);

char			*undefined_conv(char c);


char			*ft_strnew(size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t len);
int				ft_putchar(char c);
int				ft_putstr(char *s);
char			*ft_strncpy(char *dst, const char *src, size_t n);
int				ft_wcharcpy(char *dst, wchar_t uni);

void			*ft_memset(void *ptr, int c, size_t size);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t size);

int				ft_iswhitespace(char c);

size_t			ft_numlen(int n);
int				ft_atoi(const char *str);

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
