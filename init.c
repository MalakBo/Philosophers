/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:56:07 by mbouyi            #+#    #+#             */
/*   Updated: 2025/05/24 17:48:39 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init_data(t_data *data,int argc,char **argv)
{
    data->philos_number = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if(argc == 6)
        data->must_eat = ft_atoi(argv[5]);
    else
        data->must_eat = -1;
    
}
void init_philosophers(t_philo *philo,t_data *data,pthread_mutex_t *fork,pthread_mutex_t *death)
{
    int i;
    (void) death;

    i = 0;
    while(i < data->philos_number)
    {
        philo[i].id = i + 1;
        philo[i].meals_eaten = 0;
        philo[i].data = data;
        philo[i].last_meal_time = 0;
        philo[i].right_fork = &fork[i];
        philo[i].left_fork = &fork[i + 1];
        i++;
    }
}
void init_forks(pthread_mutex_t *forks,int philo_number)
{
    int i;

    i = 0;
    while(i < philo_number)
    {
        pthread_mutex_init(&forks[i],NULL);
        i++;
    }
}

