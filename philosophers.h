/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:30:25 by mbouyi            #+#    #+#             */
/*   Updated: 2025/05/21 21:35:58 by mbouyi           ###   ########.fr       */
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

typedef struct s_fork
{
    pthread_mutex_t fork;
    int id_fork;
    
} t_fork;


typedef struct s_data
{
    int philos_number;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int stop_flag;
    time_t start_sim;
    time_t end_sim;
    t_fork *forks;
    // t_philo *philos;
} t_data;

typedef struct s_philo
{
    pthread_t thread;
    int     id;
    int meals_eaten;
    long last_meal_time;
    t_fork *left;
    t_fork *right;
    t_data *data;
} t_philo;
#endif