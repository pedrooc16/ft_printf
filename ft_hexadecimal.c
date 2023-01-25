/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:04:05 by pecosta-          #+#    #+#             */
/*   Updated: 2023/01/25 15:04:05 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int ft_hexadecimal(unsigned int nb, char spc)
{
    int     counter;
    char  *  hex;

    counter = 0;
    if (spc == 'x')
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";
    
    if (nb > 9)
    {
        counter += ft_hexadecimal(nb / 16, spc);
    }
    counter += write(1, &hex[nb % 16], 1);
    return (counter);
}