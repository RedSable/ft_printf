/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:42:45 by aapricot          #+#    #+#             */
/*   Updated: 2021/04/21 21:15:39 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Can change numbers print into print_base using string:
**	"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_#"
**	Would be better, but not so fun and interesting as using bits. (^ W ^ *)
*/

#include "ft_printf.h"

void	get_u(va_list args, t_parsed_flags flags)
{
	char			*p;
	int				size;
	unsigned int	tmp;
	unsigned int	n;

	size = 1;
	n = va_arg(args, unsigned int);
	tmp = n;
	while (tmp /= 10)
		size++;
	if (!(p = (char *)malloc(size + 1)))
		return ;	//get error here!!!!!!!!!
	*(p + size) = '\0';
	while (size--)
	{
		*(p + size) = (((n % 10) < 0) ? -(n % 10) : (n % 10)) + '0';	//remove ternary
		n /= 10;
	}
	ft_putstr(p);
	free(p);
}

/*
**	Maybe combine little "x" and big "X"
*/

void	get_x(va_list args, t_parsed_flags flags)
{
	int				i;
	unsigned long	w;
	unsigned long	v;
	int				check;

	i = 0;
	v = va_arg(args, unsigned int);		//use different types with different modifyers(l, ll...)
	check = 0;
	w = 0;
	while (i++ < 16)
	{
		w = v & 0xf000000000000000;
		v = v << 4;
		w = w >> 60;
		if (w == 0 && check == 0)
			continue ;
		else
			check = 1;
		if (w < 10)
			ft_putchar('0' + w);
		else
			ft_putchar('a' + w - 10);
	}
}

void        		get_X(va_list args, t_parsed_flags flags)
{
    unsigned long	mask;
	int				i;
	unsigned long	w;
	unsigned long	v;
	int				check;

//           fedcba9876543210
	mask = 0xf000000000000000;
	i = 0;
	v = va_arg(args, unsigned long);
	check = 0;
	w = 0;
	while (i < 16)
	{
		w = v & mask;
		v = v << 4;
		w = w >> 60;
		if (w == 0 && check == 0)
		{
			i++;
			continue;
		}
		else
			check = 1;
		if (w < 10)
			ft_putchar('0' + w);
		else
			ft_putchar('A' + w - 10);
		i++;
	}
}

void        		get_f(va_list args, t_parsed_flags flags)
{
    ;
}

void				get_b(va_list args, t_parsed_flags flags)
{
	int		i;
	unsigned long	v;
	unsigned long	place;
	short			check;

	i = 0;
	v = va_arg(args, unsigned long);
	check = 0;
	place = 0;
	while (i++ < 64)
	{
		place = v & 0x8000000000000000;		//dont shure why using this mask for binary
		v = v << 1;
		place = place >> 63;
		if (place == 0 && check == 0)	//maybe exists better zeroes remover
			continue ;
		else
			check = 1;
		ft_putchar('0' + place);
	}
}
