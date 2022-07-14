/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:33:30 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/14 11:43:01 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	finished_eat_check(t_philo *philo, int *finished_eat_cnt)
{
	if (philo->eat_cnt >= philo->info->philo_must_eat)
		(*finished_eat_cnt)++;
	if (*(finished_eat_cnt) == philo->info->number_to_philo && \
			philo[0].info->philo_must_eat != -1)
	{
		philo->info->is_processing = 0;
		return (1);
	}
	return (0);
}

void	monitor_run(t_philo *philos)
{
	long	current_time;
	int		finished_eat_cnt;
	int		i;

	while (philos->info->is_processing)
	{
		i = -1;
		finished_eat_cnt = 0;
		while (++i < philos[0].info->number_to_philo)
		{
			current_time = time_stamp();
			if (current_time - philos->last_eat_time > \
					philos->info->time_to_die_m)
			{
				philos->info->is_processing = 0;
				died(philos);
				break ;
			}
			if (philos[0].info->philo_must_eat != -1)
				if (finished_eat_check(&philos[i], &finished_eat_cnt))
					break ;
		}
	}
}
