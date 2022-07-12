/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:33:30 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/12 09:38:16 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	philo_died_check(t_philo	*philos)
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
