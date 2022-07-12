/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:42:24 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/12 09:20:55 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h" 

void	*philo_run(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->info->number_to_philo == 1)
		ft_usleep(philo->info->time_to_eat_u * 2);
	if (philo->left_fork % 2 == 0)
		ft_usleep(philo->info->time_to_eat_u);
	while (philo->info->is_processing)
	{
		eating(philo);
		sleeping(philo);
		if (++philo->eat_cnt == philo->info->philo_must_eat)
			break ;
		thinking(philo);
	}
	return (NULL);
}

int	philo_died_check(t_philo	*philos)
{
	long	current_time;

	current_time = time_stamp();
	if (current_time - philos->last_eat_time >= \
			philos->info->time_to_die_m)
	{
		philos->info->is_processing = 0;
		died(philos);
		return (1);
	}
	return (0);
}

void	monitor_run(t_philo *philos)
{
	int		finished_eat_cnt;
	int		i;

	while (philos->info->is_processing)
	{
		i = -1;
		finished_eat_cnt = 0;
		while (++i < philos[0].info->number_to_philo)
		{
			if (philo_died_check(&philos[i]))
				break ;
			if (philos[i].eat_cnt >= philos[i].info->philo_must_eat)
				finished_eat_cnt++;
			if (finished_eat_cnt == philos[i].info->number_to_philo && \
					philos[0].info->philo_must_eat != -1)
			{
				philos->info->is_processing = 0;
				break ;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	t_philo		*philos;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	init(argc, argv, &philos);
	philo_thread_init(philos);
	monitor_run(philos);
	i = -1;
	while (++i < philos[0].info->number_to_philo)
		pthread_detach(philos[i].tid);
	ft_usleep(500000);
	return (0);
}
