/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sophy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:52:29 by mac               #+#    #+#             */
/*   Updated: 2025/05/28 17:16:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void eat_philo(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    printf("%ld %d has taken the right fork\n",c_time(philo->data),philo->id);
    pthread_mutex_lock(philo->left_fork);
    printf("%ld %d has taken the left fork\n",c_time(philo->data),philo->id);
    philo->last_meal_time = get_time();
    printf("%ld %d is eating\n",c_time(philo->data),philo->id);
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}
void sleep_philo(t_philo *philo)
{
    printf("%ld %d is sleeping\n",c_time(philo->data),philo->id);
    usleep(philo->data->time_to_sleep * 1000);
}
void think(t_philo *philo)
{
    printf("%ld %d is thinking\n",c_time(philo->data),philo->id);
}
void *monitor(void *arg)
{
    t_philo *philo;
    t_data *data;
    int i;
    int done;

    philo = (t_philo *)arg;
    data = philo[0].data;
    
}
