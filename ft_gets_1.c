/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:27:26 by aapricot          #+#    #+#             */
/*   Updated: 2021/04/20 23:05:10 by aapricot         ###   ########.fr       */
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

	result = ft_itoa(va_arg(args, int));
	ft_putstr(result);
	free(result);
}

void        get_o(va_list args, t_parsed_flags flags)
{
    int				i;
	unsigned long	v;
	unsigned long	place;
	short			check;

	i = 0;
	v = va_arg(args, unsigned long);
	check = 0;
	place = 0;
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


	// int		i;
	// unsigned long	v;
	// unsigned long	place;
	// short			check;

	// i = 0;
	// v = va_arg(args, unsigned long);
	// check = 0;
	// place = 0;
	// while (i++ < 64)
	// {
	// 	place = v & 0x8000000000000000;		//dont shure why using this mask for binary
	// 	v = v << 1;
	// 	place = place >> 63;
	// 	if (place == 0 && check == 0)	//maybe exists better zeroes remover
	// 		continue ;
	// 	else
	// 		check = 1;
	// 	ft_putchar('0' + place);
	// }