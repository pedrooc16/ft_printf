/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:22:18 by pecosta-          #+#    #+#             */
/*   Updated: 2023/01/24 15:22:18 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(char c)
{
	if (c == 'x' || c == 'p' || c == 'c' 
	|| c == 'X' || c == 'd' || c == '%' 
	|| c == 'i' || c == 's' || c == 'u')
			return (1);
		return (0);
}

static int		ft_placeholder(va_list args, char spc);

int	ft_printf(const char *format, ...)
{
    va_list args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, format); //inicializar a lista
	while (format[i])
		{
			if (format[i++] == '%')
			{
			if (check_flag(format[i++]) == 1)
			{
				counter += ft_placeholder(args, format[i]);
				i++;	
			}
		}
			counter += ft_putchar(format[i]);
			i++;
		}
		va_end(args);
		return (counter);
}

int		ft_placeholder(va_list args, char spc)
{
	if (spc == 'c')
			return (ft_putchar(va_arg(args, int)));
	else if (spc == 's')
			return (ft_putstring(va_arg(args, char *)));
	else if (spc == 'd' || spc == 'i')
			return (ft_putnbr(va_arg(args, int)));
	else if (spc == 'x')
			return (ft_hexadecimal(va_arg(args, unsigned int), 'x'));
	else if (spc == 'X')
			return (ft_hexadecimal(va_arg(args, unsigned int), 'X'));
	else if (spc == '%')
			return (ft_putchar('%'));		
	else if (spc == 'u')
			return (ft_unsigned_decimal(va_arg(args, unsigned int)));
	else if (spc == 'p')
			return (ft_print_address(va_arg(args, unsigned long int)));		
	return (0);		
}

