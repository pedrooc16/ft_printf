/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:29:55 by pecosta-          #+#    #+#             */
/*   Updated: 2023/01/24 17:29:55 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    return(write(1, &c, 1));
}

int ft_putstring(char *s)
{
    if (!s)
        return(write(1, "(null)", 6));
    int     i;
    int     counter;

    i = 0;
    counter = 0;
    
    while (s[i] != '\0')
    {
       counter += ft_putchar(s[i]);
       i++;
    }
    return (counter);
}