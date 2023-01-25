/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecosta- <pecosta-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:48:54 by pecosta-          #+#    #+#             */
/*   Updated: 2023/01/18 17:48:54 by pecosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
    int decimal = 2779;
    char hex_str[100];
    int i=0;
    while(decimal!=0)
    {
        int temp = decimal%16;
        if(temp<10)
        {
            hex_str[i] = temp+48;
            write(1, &hex_str[i], 1);
            i++;
        }
        else
        {
            hex_str[i] = temp+55;
                write(1, &hex_str[i], 1);
            i++;
        }
        decimal = decimal/16;
    }
    hex_str[i] = '\0';
}