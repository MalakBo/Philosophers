/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:30:25 by mbouyi            #+#    #+#             */
/*   Updated: 2025/05/22 15:55:46 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>


typedef struct s_data
{
    int philos_number;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
} t_data;

typedef struct s_philo
{
    pthread_t thread;
    int     id;
    int meals_eaten;
    long last_meal_time;
    t_data *data;
} t_philo;
#endif