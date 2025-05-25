/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:36:15 by mbouyi            #+#    #+#             */
/*   Updated: 2025/05/24 17:59:58 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <time.h>
int valid_input(int argc,char **argv)
{
    int i;

    i = 1;
	if (argc != 5 && argc != 6)
	{
		write(2, "zid shwiya wla nqes a dk lmo3a9\n", 32);
		return (0);
	}
	while (i < argc)
	{
		if (!is_digit(argv[i]))
		{
			write(2, "dkhli ghi arqam a ikhan\n", 24);
			return (0);
		}
		i++;
	}
	return (1);
}
int main(int argc, char **argv)
{
    t_data data;
    pthread_mutex_t forks[400];
    t_philo philos[400];

    if(!valid_input(argc,argv))
        return(1);
    init_data(&data,argc,argv);
    printf("%d %d %d %d %d\n", data.philos_number, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.must_eat);
    write(1, "hakak a dk lmongol\n", 19);
    init_forks(forks,data.philos_number);
    init_philosophers(philos,&data,forks,&data.death);
    create_threads(philos,&data);
    return 0;
}
