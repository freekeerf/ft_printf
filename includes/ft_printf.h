/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:57:16 by evlasov           #+#    #+#             */
/*   Updated: 2018/09/26 20:57:17 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <locale.h>
# include <limits.h>

typedef	struct	s_flags
{
	int			count;
	int			plus;
	int			minus;
	int			hash;
	int			space;
	int			zero;
	int			width;
	int			precision;
	int			size;
	int			conversion;
	char		*result;
	int			k;
	char		*tmp;
	int			rez;
	int			point;
}				t_flags;

int				ft_printf(char *format, ...);
void			args_handling(const char *format, va_list args, t_flags *flags);
void			ft_init(t_flags *flags);
int				apply_flags(char c, va_list args, t_flags *flags);
int				apply_id(va_list args, t_flags *flags);
int				apply_s(va_list args, t_flags *flags);
char			*ft_itoa_ll(intmax_t n);
int				apply_sl(va_list args, t_flags *flags);
int				apply_c(va_list args, t_flags *flags);
int				apply_cl(va_list args, t_flags *flags);
int				apply_o(va_list args, t_flags *flags);
int				apply_u(va_list args, t_flags *flags);
int				apply_x(va_list args, t_flags *flags);
int				apply_p(va_list args, t_flags *flags);
int				ft_itoa_cc(intmax_t n, char **buf, int cc);
char			ft_simb(int n);
int				ft_fill(t_flags *flags, int dif);
int				ft_hash_plus_space(t_flags *flags);
int				ft_uitoa_cc(uintmax_t n, char **buf, int cc, int x);
void			print_id(t_flags *flags, int len);
void			print_x(t_flags *flags, int len);
void			print_o(t_flags *flags, int len);
char			*ft_uitoa_ll(uintmax_t n);
void			print_u(t_flags *flags, int len);
void			print_s(t_flags *flags);
void			print_c(t_flags *flags);
void			print_p(t_flags *flags);
void			print_per(t_flags *flags);
int				flags_handling(const char *format, int i, t_flags *flags);
int				size_mod(const char *format, int i, t_flags *flags);
int				conversion_handling(const char *format, int i, t_flags *flags);
int				unicode(unsigned int i, char *tmp, int k);
int				uni_len(unsigned int i);

#endif
