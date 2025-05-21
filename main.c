/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:36:15 by mbouyi            #+#    #+#             */
/*   Updated: 2025/05/22 00:28:03 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
int is_digit(char *n)
{
    int i = 0;
    while(n[i])
    {
        if(n[i] >= '0' && n[i] <= '9')
            return 1;
        return 0;
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc == 5 || argc == 6)
    {
        while (i < argc)
        {
            if (!is_digit(argv[i]))
            {
                write(2, "dkhli ghi arqam akhoya\n", 24);
                return 1;
            }
            i++;
        }
        write(1, "hakak\n", 6);
    }
    else 
    {
        write(2, "zid shwiya wla nqes\n", 21);
        return 1;
    }
    return 0;
}