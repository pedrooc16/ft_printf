/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:43:46 by pecosta-          #+#    #+#             */
/*   Updated: 2023/01/25 11:43:46 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int nb)
{
    int     counter;
    char *  dec;

    counter = 0;
    dec = "0123456789";
    if (nb == -2147483648)
    {
        return(write(1, "-2147483648", 11));
    }
    if (nb < 0)
    {
        counter = write(1, "-", 1);
        nb *= -1;
    }

    if (nb > 9)
    {
        counter += ft_putnbr(nb / 10);
    }
	counter += write(1, &dec[nb % 10], 1);
    return (counter);
}

/*int main()
{
    int d = ft_putnbr(-4555923);
    printf("\n%d", d);
}*/
