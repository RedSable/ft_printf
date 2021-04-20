/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:33:19 by aapricot          #+#    #+#             */
/*   Updated: 2021/04/20 23:09:39 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "libft.h"

t_selector			g_selector[] = {
	{'c', get_c},
	{'s', get_s},
	{'p', get_p},
	{'d', get_d},
	{'i', get_d},
	{'o', get_o},
	{'u', get_u},
	{'x', get_x},
	{'X', get_X},
	{'f', get_f},
	{'b', get_b}
};

int					g_selector_size = sizeof(g_selector) / sizeof(t_selector);

t_parsed_flags		get_parsed_flags(char **fmt)
{
	t_parsed_flags	flags;

	get_accuracy(flags.accuracy, fmt);
	if (**fmt == '.')
		*fmt += 1;
	get_lenght(flags.lenght, fmt);
	get_spec(flags.spec, fmt);
	get_flag(&flags.flag, fmt);
	return (flags);
}

//Приходит что записать

int					choose_func(t_parsed_flags flags, va_list args)
{
	int				i;

	i = 0;
	// printf("%c\n\n", flags.flag);
	while (i < g_selector_size)
	{
		if (flags.flag == g_selector[i].flag)
		{
			g_selector[i].func(args, flags);
			break ;
		}
		i++;
	}
	return (0);
}

int					ft_printf(const char *format, ...)
{
	va_list			args;
	int				value;
	t_parsed_flags	flags;

	va_start(args, format);
	while (*format)
	{
		if ((*format == '%') && (format[1] == '%'))
		{
			ft_putchar('%');
			format = format + 2;
			continue ;
		}
		if (*format == '%')
		{
			format++;
			flags = get_parsed_flags((char **)&format);
			choose_func(flags, args);
			continue ;
		}
		ft_putchar(*format);
		format++;
		// clean_struct(flags);
	}
	va_end(args);
	return (0);
}

int		main()
{
	char	*op = "kek";
	char	*po;

	po = op;
	ft_printf("%s %c %x\n%p\n", "Hello", 'q', UINT64_MAX - 2, &po);
	printf("%s %c %x\n%p", "Hello", 'q', UINT64_MAX - 2, &po);
	return(0);
}
