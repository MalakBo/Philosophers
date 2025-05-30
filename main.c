/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:36:15 by mbouyi            #+#    #+#             */
/*   Updated: 2025/05/30 22:44:56 by mbouyi           ###   ########.fr       */
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
    t_data *data;
    t_philo *philos;

    if (valid_input(argc,argv) == 0)
	{
        return(1);
	}
	data = malloc(sizeof(t_data));
	memset(data, 0, sizeof(t_data));
   
    init_data(data,argc,argv);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_number);
	if(!data->forks)
		return(1);
	philos = malloc(sizeof(t_philo) * data->philos_number);
	if(!philos)
	{
		// free(forks);
		return(1);
	}
	memset(philos, 0, sizeof(t_philo));
    init_forks(data->forks,data->philos_number);
    init_philosophers(philos,data,data->forks,&data->dead);
    create_threads(philos,data);
	// free(forks);
	// free(philos);
    return 0;
}
