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

int		ft_placeholder(va_list args, char spc);

static int	check_flag(char c)
{
	if (c == 'x' || c == 'p' || c == 'c' 
	|| c == 'X' || c == 'd' || c == '%' 
	|| c == 'i' || c == 's' || c == 'u')
			return (1);
		return (0);
}

int	ft_printf(const char *format, ...)
{
    va_list args;
	int		counter;

	counter = 0;
	va_start(args, format); //inicializar a lista
	while (*format != '\0')
		{
			if (*format == '%')
			{
			 format++;
			if (check_flag(*format) == 1)
			{
				counter += ft_placeholder(args, *format);
			}
		}
		else
			    counter += ft_putchar(*format);
			format++;
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

/* va_list holds the information needed by va_start, va_arg, va_copy, va_end;
*va_list is a structure... using pointers for accessing values in stack;
*macro void va_start(va_list ap, last_arg) initializes ap variable to be 
*used with the va_arg and va_end macros. 
*The va_start() macro initializes ap for subsequent use by va_arg(), 
va_copy() and va_end(), and must be called first.
*The last_arg is the last known fixed argument being passed to the function i.e. the argument before the ellipsis.
*ap − This is the object of va_list and it will hold the 
*information needed to retrieve the additional arguments with va_arg
*va_arg will pull the arguments one by one, in the order they are listed...;
*...va_arg syntax= va_arg(va_list, datatype), e.g.datatype could be 'int';
* each va_arg invocation modifies va_list to point the next variable argument;
*If the type of the next argument in ap (after promotions) is not compatible with T, the behavior is undefined, unless:
one type is a signed integer type, the other type is the corresponding unsigned integer type,
*and the value is representable in both types; or
*0x is the prefix to indicate that the address is being printed as hexadecimal;
*printf will return the number of charachters written, in this case, the counter;
*
*/

