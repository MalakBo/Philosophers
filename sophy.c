/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sophy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:52:29 by mac               #+#    #+#             */
/*   Updated: 2025/05/30 22:47:28 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void eat_philo(t_philo *philo)
{
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;

    if(philo->left_fork > philo->right_fork)
    {
        first_fork = philo->left_fork;
        second_fork = philo->right_fork;
    }
    else
    {
        first_fork = philo->right_fork;
        second_fork = philo->left_fork;
    }
    pthread_mutex_lock(first_fork );
    printmsg(philo,"has taken the right fork");
    pthread_mutex_lock(second_fork);
    printmsg(philo,"has taken the left fork");

    philo->last_meal_time = get_time();
    
    printmsg(philo,"is eating");
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_unlock(first_fork);
    pthread_mutex_unlock(second_fork);
}

void sleep_philo(t_philo *philo)
{
    printmsg(philo,"is sleeping");
    usleep(philo->data->time_to_sleep * 1000);
}
void think(t_philo *philo)
{
    printmsg(philo,"is thinking");
    // usleep(200);
}
void *monitor(void *arg)
{
    t_philo *philo;
    t_data *data;
    int i;
    size_t time;
    // int done;

    philo = (t_philo *)arg;
    data = philo[0].data;
    while(1)
    {
        i = 0;
        // done = 0;
        usleep(data->time_to_die * 1000);
        while(i < data->philos_number)
        {
            pthread_mutex_lock(&philo[i].meal);
            time = get_time() - philo[i].last_meal_time;
            pthread_mutex_unlock(&philo[i].meal);   
                     
            pthread_mutex_lock(&data->dead);
            if(time > data->time_to_die)
            {
                printmsg(&philo[i], "died");
                data->dead_flag = 1;
                pthread_mutex_unlock(&data->dead);            
                return NULL;             
            }
            pthread_mutex_unlock(&data->dead);
            i++;
        }
    }
    return NULL;
}
