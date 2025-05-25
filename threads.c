/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:47:52 by mac               #+#    #+#             */
/*   Updated: 2025/05/25 18:25:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void *create(void *arg)
{
    t_philo *philos;

    philos = (t_philo *)arg;
    if(philos->id % 2 != 0)
        usleep(100);
    while(1)
    {
        eat_philo(philos);
        sleep_philo(philos);
        think(philos);
    }
    return NULL;
}

void create_threads(t_philo *philo,t_data *data)
{
    int i;

    i = 0;
    while(i < data->philos_number)
    {
        pthread_create(&philo[i].thread,NULL,create,&philo[i]);
        i++;
    }
    i = 0;
    while(i < data->philos_number)
    {
        pthread_join(philo[i].thread,NULL);
        i++;
    }
}