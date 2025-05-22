/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:36:15 by mbouyi            #+#    #+#             */
/*   Updated: 2025/05/22 18:51:49 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
long ft_atoi(char *s)
{
    int i;
    int sign;
    long r;

    i = 0;
    sign = 1;
    r = 0;
    while(s[i] == ' ' || (s[i] >= 9 && s[i] < 13))
        i++;
    if(s[i] == '+')
        i++;
    else if(s[i] == '-')
    {
        sign = -1;
        i++;
    }
    while(s[i] && (s[i] >= '0' && s[i] <= '9'))
    {
        r = r * 10 + (s[i] - '0');
        i++;
    }
    return (r * sign);
}
int init_data(t_data *data,int argc,char **argv)
{
    
}
int is_digit(char *n)
{
    int i = 0;
    while(n[i])
    {
        if(n[i] < '0' || n[i] > '9')
            return 0;
        i++;
    }
    return 1;
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
                write(2, "dkhli ghi arqam a ikhan\n", 24);
                return 1;
            }
            i++;
        }
        write(1, "hakak a dk lmongol\n", 19);
    }
    else 
    {
        write(2, "zid shwiya wla <nqes a dk lmo3a9\n", 32);
        return 1;
    }
    
    return 0;
}
