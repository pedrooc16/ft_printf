/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:44:35 by pecosta-          #+#    #+#             */
/*   Updated: 2023/01/25 16:44:35 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_hex(long unsigned int nb);

int ft_print_address(long unsigned int nb)
{
    int     counter;

    if (nb == 0)
        return(write(1, "(nil)", 5));
    else
    {
        counter = write(1, "0x", 2);
        counter += print_hex(nb);
        return (counter);    
    }
}

static int print_hex(long unsigned int nb)
{
    int         counter;
    char    *hex;

    counter = 0;
    hex = "0123456789abcdef";
    if (nb >= 16) 
    {
       counter += print_hex(nb / 16);
    }
    counter += write(1, &hex[nb % 16], 1);
    return (counter);
}