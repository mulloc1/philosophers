/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:23:18 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/14 11:24:10 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_t	philo_thread_init(t_philo *philos)
{
	int			i;
	long		time;
	pthread_t	monitor_tid;

	monitor_tid = NULL;
	time = time_stamp();
	i = -1;
	while (++i < philos[0].info->number_to_philo)
	{
		philos[i].run_time = time;
		philos[i].last_eat_time = time;
		pthread_mutex_init(&philos[0].m_forks[i], NULL);
		pthread_create(&philos[i].tid, NULL, philo_run, (void *)&philos[i]);
	}
	pthread_mutex_init(philos[0].m_printable, NULL);
	return (monitor_tid);
}
