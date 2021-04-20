/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:47:35 by aapricot          #+#    #+#             */
/*   Updated: 2021/04/14 21:37:33 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_accuracy(int ac, char **fmt)
{
	ac = 0;
	return (0);
}

int			get_lenght(int lenght, char **fmt)
{
	lenght = 0;
	return (0);
}

int			get_spec(int spec, char **fmt)
{
	spec = 0;
	return (0);
}

int			get_flag(char *flag, char **fmt)
{
	*flag = **fmt;
	*fmt += 1;
	return (0);
}