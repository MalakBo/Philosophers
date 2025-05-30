/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:24:31 by mac               #+#    #+#             */
/*   Updated: 2025/05/29 22:32:13 by mbouyi           ###   ########.fr       */
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

void printmsg(t_philo *philo,char *msg)
{
    pthread_mutex_lock(&philo->data->print);
    pthread_mutex_lock(&philo->data->dead);
    if (!philo->data->dead_flag)
        printf("%ld %d %s\n",c_time(philo->data),philo->id,msg);
    pthread_mutex_unlock(&philo->data->dead);
    pthread_mutex_unlock(&philo->data->print);
}
