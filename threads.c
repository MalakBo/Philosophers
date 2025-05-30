/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:47:52 by mac               #+#    #+#             */
/*   Updated: 2025/05/30 22:27:17 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void *create(void *arg)
{
    t_philo *philos;

    philos = (t_philo *)arg;
    philos->last_meal_time =  philos->data->start_time;
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
    data->start_time = get_time();
    i = 0;
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
