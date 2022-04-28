/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:03:48 by jaebae            #+#    #+#             */
/*   Updated: 2022/04/28 13:43:53 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_run(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->info->number_to_philo == 1)
		died(philo);
	if (philo->my_pork % 2 == 0)
		ft_usleep(philo->info->time_to_eat_u);
	while (1)
	{
		pthread_mutex_lock(&philo->m_porks[philo->my_pork]);
		pthread_mutex_lock(&philo->m_porks[philo->next_pork]);
		eating(philo);
		pthread_mutex_unlock(&philo->m_porks[philo->next_pork]);
		pthread_mutex_unlock(&philo->m_porks[philo->my_pork]);
		sleeping(philo);
		thinking(philo);
		philo->eat_cnt++;
		ft_usleep(150);
	}
	return (NULL);
}

void	*monitor_run(void *ptr)
{
	t_philo	*philo;
	int		finished_eat_cnt;
	int		i;

	philo = (t_philo *)ptr;
	finished_eat_cnt = 0;
	while (philo->info->philo_must_eat != -1)
	{
		i = -1;
		while (++i < philo[0].info->number_to_philo)
		{
			if (philo[i].eat_cnt == philo[i].info->philo_must_eat)
				finished_eat_cnt++;
			if (finished_eat_cnt == philo[i].info->number_to_philo)
				finished_eat_exit(philo);
		}
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		error_handler("argc\n", 1);
	init(argc, argv, &philos);
	philo_thread_init(philos);
}
