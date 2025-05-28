/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:24:31 by mac               #+#    #+#             */
/*   Updated: 2025/05/25 22:15:39 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
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
size_t get_time(void)
{
    struct timeval time;

    gettimeofday(&time,NULL);
    return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
size_t c_time(t_data *data)
{
    return(get_time()- data->start_time);
}
