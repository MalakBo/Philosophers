/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sophy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:52:29 by mac               #+#    #+#             */
/*   Updated: 2025/05/30 00:45:40 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void eat_philo(t_philo *philo)
{
// if (philo->left_fork == philo->right_fork)
// {
//     pthread_mutex_lock(philo->right_fork);
//     printmsg(philo,"has taken the right fork");
//     usleep(philo->data->time_to_die * 1000);
//     pthread_mutex_unlock(philo->right_fork);
//     return;
// }
    pthread_mutex_lock(philo->right_fork);
    printmsg(philo,"has taken the right fork");
    pthread_mutex_lock(philo->left_fork);
    printmsg(philo,"has taken the left fork");
    philo->last_meal_time = get_time();
    printmsg(philo,"is eating");
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}
void sleep_philo(t_philo *philo)
{
    printmsg(philo,"is sleeping");
    usleep(philo->data->time_to_sleep * 1000);
}
void think(t_philo *philo)
{
    printmsg(philo,"is thinking");
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
        while(i < data->philos_number)
        {
            pthread_mutex_lock(&philo[i].meal);
            time = get_time() - philo[i].last_meal_time;
            pthread_mutex_unlock(&philo[i].meal);            
            pthread_mutex_lock(&data->dead);
            if(time > data->time_to_die && !data->dead_flag)
            {
                pthread_mutex_unlock(&data->dead);
                printmsg(&philo[i], "died");
                pthread_mutex_lock(&data->dead);
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
