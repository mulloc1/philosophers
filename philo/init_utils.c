/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:04:52 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/11 18:07:32 by jaebae           ###   ########.fr       */
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

t_info	*info_init(int argc, char *argv[])
{	
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->number_to_philo = ft_atoi(argv[1]);
	info->time_to_die_m = ft_atol(argv[2]);
	info->time_to_eat_m = ft_atol(argv[3]);
	info->time_to_sleep_m = ft_atol(argv[4]);
	info->time_to_die_u = info->time_to_die_m * 1000;
	info->time_to_eat_u = info->time_to_eat_m * 1000;
	info->time_to_sleep_u = info->time_to_sleep_m * 1000;
	info->philo_must_eat = -1;
	info->is_processing = 1;
	if (argc == 6)
		info->philo_must_eat = ft_atoi(argv[5]);
	return (info);
}

void	init(int argc, char *argv[], t_philo **philos)
{
	t_info			*info;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	*m_printable;
	int				i;

	info = info_init(argc, argv);
	*philos = ft_calloc(info->number_to_philo, sizeof(t_philo));
	m_forks = malloc(sizeof(pthread_mutex_t) * (info->number_to_philo));
	m_printable = malloc(sizeof(pthread_mutex_t));
	i = -1;
	while (++i < info->number_to_philo)
	{
		(*philos)[i].info = info;
		(*philos)[i].left_fork = i;
		(*philos)[i].right_fork = (i + 1) % info->number_to_philo;
		(*philos)[i].m_forks = m_forks;
		(*philos)[i].m_printable = m_printable;
	}
}
