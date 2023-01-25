/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:53:36 by pecosta-          #+#    #+#             */
/*   Updated: 2023/01/25 15:53:36 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unsigned_decimal(unsigned int nb)
{
    int     counter;
    char * hex;

    hex = "0123456789";
    counter = 0;
    if (nb > 9)
    {
        counter += ft_unsigned_decimal(nb / 10);
    }
    counter += write(1, &hex[nb % 10], 1);
    return (counter);
}