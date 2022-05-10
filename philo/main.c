/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:03:48 by jaebae            #+#    #+#             */
/*   Updated: 2022/05/10 23:24:11 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_run(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->info->number_to_philo == 1)
		ft_usleep(philo->info->time_to_eat_u * 2);
	if (philo->left_fork % 2 == 1)
		ft_usleep(philo->info->time_to_eat_u);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		philo->eat_cnt++;
	}
	return (NULL);
}

void	*monitor_run(void *ptr)
{
	t_philo	*philo;
	long	current_time;
	int		finished_eat_cnt;
	int		i;

	philo = (t_philo *)ptr;
	finished_eat_cnt = 0;
	while (1)
	{
		i = -1;
		while (++i < philo[0].info->number_to_philo)
		{
			current_time = time_stamp();
			if (current_time - philo[i].last_eat_time >= \
					philo->info->time_to_die_m)
				died(philo);
			if (philo[i].eat_cnt == philo[i].info->philo_must_eat)
				finished_eat_cnt++;
			if (finished_eat_cnt == philo[i].info->number_to_philo && \
					philo[0].info->philo_must_eat != -1)
				finished_eat_exit(philo);
		}
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		error_handler("argc few\n", 1);
	init(argc, argv, &philos);
	philo_thread_init(philos);
}
