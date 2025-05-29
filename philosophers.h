/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:30:25 by mbouyi            #+#    #+#             */
/*   Updated: 2025/05/29 15:25:36 by mac              ###   ########.fr       */
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
    size_t time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
    size_t start_time;
    int dead_flag; 
    pthread_mutex_t dead;
    pthread_mutex_t print;
    pthread_mutex_t print;
} t_data;

typedef struct s_philo
{
    pthread_t thread;
    int     id;
    int meals_eaten;
    long last_meal_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t meal;
    t_data *data;
} t_philo;

long ft_atoi(char *s);
int is_digit(char *n);
void init_data(t_data *data,int argc,char **argv);
void init_philosophers(t_philo *philo,t_data *data,pthread_mutex_t *fork,pthread_mutex_t *death);
void init_forks(pthread_mutex_t *forks,int philo_number);
size_t get_time(void);
void create_threads(t_philo *philo,t_data *data);
void eat_philo(t_philo *philo);
void sleep_philo(t_philo *philo);
void think(t_philo *philo);
size_t c_time(t_data *data);
void *monitor(void *arg);
void printmsg(t_philo *philo,char *msg);
#endif