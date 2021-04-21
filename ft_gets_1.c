/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:27:26 by aapricot          #+#    #+#             */
/*   Updated: 2021/04/21 21:25:21 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        get_c(va_list args, t_parsed_flags flags)
{
    ft_putchar(va_arg(args, int));
}

void        get_s(va_list args, t_parsed_flags flags)
{
    ft_putstr(va_arg(args, char *));
}

void        get_p(va_list args, t_parsed_flags flags)
{
	ft_putstr("0x");
	get_x(args, flags);
}

void        get_d(va_list args, t_parsed_flags flags)
{
    char	*result;

	result = ft_itoa(va_arg(args, int));	//need to change itoa for different types(32, 64...)
	ft_putstr(result);
	free(result);
}

/*
**	<<<<<<<<<<<<<<<<<<<<<<<<<< GET_O >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
**	First variable "place" calculated for one left bit in octet,
**	because octets uses 3 bits for 1 digit.
**	So in cicle I use last 63 bits.
**	0x7000000000000000 is a mask where one digit uses 4 bits,
**	so 7 equal 0111. I move bits for compare digits and print its.
*/

void        get_o(va_list args, t_parsed_flags flags)
{
    int				i;
	unsigned long	v;
	unsigned long	place;
	short			check;

	i = 0;
	v = va_arg(args, unsigned long);
	check = 0;
	place = (v >> 63) & 0x1;
	if (place != 0)
		ft_putchar('0' + place);
	while (i++ < 21)
	{
		place = v & 0x7000000000000000;
		v = v << 3;
		place = place >> 60;
		if (place == 0 && check == 0)
			continue ;
		else
			check = 1;
		ft_putchar('0' + place);
	}
}
