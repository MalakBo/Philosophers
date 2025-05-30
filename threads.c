/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:47:52 by mac               #+#    #+#             */
/*   Updated: 2025/05/30 00:27:08 by mbouyi           ###   ########.fr       */
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
        printmsg(philos,"has taken the right fork");
        usleep(philos->data->time_to_die * 1000);
        printmsg(philos,"died");
        pthread_mutex_unlock(philos->right_fork);
        return NULL;
    }
    if(philos->id % 2 != 0)
        usleep(100);
    while(1)
    {
        pthread_mutex_lock(&philos->data->philo_mutex);
        pthread_mutex_lock(&philos->data->dead);
        if(philos->data->dead_flag)
        {
            pthread_mutex_unlock(&philos->data->dead);
            pthread_mutex_unlock(&philos->data->philo_mutex);
            break;
        }
        pthread_mutex_unlock(&philos->data->dead);        
        eat_philo(philos);
        sleep_philo(philos);
        think(philos);
        pthread_mutex_unlock(&philos->data->philo_mutex);
    }
    return NULL;
}

void create_threads(t_philo *philo,t_data *data)
{
    int i;

    i = 0;
    pthread_t moni;
    while (i < data->philos_number)
    {
        pthread_mutex_lock(&philo[i].data->philo_mutex);
        pthread_mutex_lock(&philo[i].meal);
        philo[i].last_meal_time = get_time();
        pthread_mutex_unlock(&philo[i].meal);
        pthread_mutex_unlock(&philo[i].data->philo_mutex);
        i++;
    }
    i = 0;
    while(i < data->philos_number)
    {
        pthread_mutex_lock(&philo[i].data->philo_mutex);
        pthread_create(&philo[i].thread,NULL,create,&philo[i]);
        pthread_mutex_unlock(&philo[i].data->philo_mutex);
        i++;
    }
    pthread_create(&moni,NULL,&monitor,philo);
    i = 0;
    
    while(i < data->philos_number)
    {
        pthread_mutex_lock(&philo[i].data->philo_mutex);
        pthread_join(philo[i].thread,NULL);
        pthread_mutex_unlock(&philo[i].data->philo_mutex);
        i++;
    }
    pthread_join(moni,NULL);
}
