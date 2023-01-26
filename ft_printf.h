/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:21:59 by pecosta-          #+#    #+#             */
/*   Updated: 2023/01/24 15:21:59 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int ft_putchar(int c);
int ft_putstring(char *s);
int ft_putnbr(int nb);
int ft_hexadecimal(unsigned int nb, char spc);
int ft_unsigned_decimal(unsigned int nb);
int ft_print_address(long unsigned int nb);


#endif
