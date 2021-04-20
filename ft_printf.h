/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:33:26 by aapricot          #+#    #+#             */
/*   Updated: 2021/04/20 21:23:21 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

typedef struct s_selector		t_selector;
typedef struct s_parsed_flags	t_parsed_flags;
typedef enum e_flags			t_flags;
typedef enum e_spec				t_spec;

enum							e_spec
{
	hh,
	h,
	l,
	ll,
	L,
};

// enum							e_flags
// {
// 	c,
// 	s,
// 	p,
// 	d,
// 	i,
// 	o,
// 	u,
// 	x,
// 	X,
// 	f,
// };

struct							s_parsed_flags
{
	int							accuracy;
	int							lenght;
	t_spec						spec;
	char						flag;
};

struct						s_selector
{
	char					flag;
	void					(*func)();
};

int							get_accuracy(int ac, char **fmt);
int							get_lenght(int lenght, char **fmt);
int							get_spec(int spec, char **fmt);
int							get_flag(char *flag, char **fmt);
void						get_c(va_list args, t_parsed_flags flags);
void						get_s(va_list args, t_parsed_flags flags);
void						get_p(va_list args, t_parsed_flags flags);
void						get_d(va_list args, t_parsed_flags flags);
void						get_b(va_list args, t_parsed_flags flags);
void						get_o(va_list args, t_parsed_flags flags);
void						get_u(va_list args, t_parsed_flags flags);
void						get_x(va_list args, t_parsed_flags flags);
void						get_X(va_list args, t_parsed_flags flags);
void						get_f(va_list args, t_parsed_flags flags);
