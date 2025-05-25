/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sophy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:52:29 by mac               #+#    #+#             */
/*   Updated: 2025/05/25 18:23:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void eat_philo(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    printf("%ld %d has taken the right fork\n",get_time(),philo->id);
    pthread_mutex_lock(philo->left_fork);
    printf("%ld %d has taken the left fork\n",get_time(),philo->id);
    printf("%ld %d is eating\n",get_time(),philo->id);
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}
void sleep_philo(t_philo *philo)
{
    printf("%ld %d is sleeping\n",get_time(),philo->id);
    usleep(philo->data->time_to_sleep * 1000);
}
void think(t_philo *philo)
{
    printf("%ld %d is thinking\n",get_time(),philo->id);
}
