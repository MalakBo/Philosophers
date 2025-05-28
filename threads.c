/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:47:52 by mac               #+#    #+#             */
/*   Updated: 2025/05/28 23:35:51 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void *create(void *arg)
{
    t_philo *philos;

    philos = (t_philo *)arg;
    if (philos->data->philos_number == 1)
    {
        pthread_mutex_lock(philos->right_fork);
        printf("%ld %d has taken a fork\n", c_time(philos->data), philos->id);
        usleep(philos->data->time_to_die * 1000);
        printf("%ld %d died\n", c_time(philos->data), philos->id);
        pthread_mutex_unlock(philos->right_fork);
        return NULL;
    }
    if(philos->id % 2 != 0)
        usleep(100);
    while(1)
    {
        pthread_mutex_lock(&philos->data->dead);
        if(philos->data->dead_flag)
        {
            pthread_mutex_unlock(&philos->data->dead);
            break;
        }
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
    pthread_t moni;
    while(i < data->philos_number)
    {
        pthread_create(&philo[i].thread,NULL,create,&philo[i]);
        i++;
    }
    pthread_create(&moni,NULL,&monitor,philo);
    i = 0;
    while(i < data->philos_number)
    {
        pthread_join(philo[i].thread,NULL);
        i++;
    }
    pthread_join(moni,NULL);
}