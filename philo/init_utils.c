/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:04:52 by jaebae            #+#    #+#             */
/*   Updated: 2022/04/28 11:36:41 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_thread_init(t_philo *philos)
{
	int			i;
	long		time;
	pthread_t	monitor_tid;

	i = -1;
	monitor_tid = NULL;
	time = time_stamp();
	while (++i < philos[1].info->number_to_philo)
	{
		philos[i].run_time = time;
		philos[i].last_eat_time = time;
		pthread_mutex_init(&philos[1].m_porks[i], NULL);
		pthread_create(&philos[i].tid, NULL, philo_run, (void *)&philos[i]);
	}
	pthread_create(&monitor_tid, NULL, monitor_run, (void *)philos);
	pthread_mutex_init(&philos[1].m_locker[M_PRINTABLE], NULL);
	pthread_mutex_init(&philos[1].m_locker[M_FINISHED_EAT], NULL);
	i = -1;
	while (++i < philos[1].info->number_to_philo)
		pthread_join(philos[i].tid, NULL);
	pthread_join(monitor_tid, NULL);
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
	if (argc == 6)
		info->philo_must_eat = ft_atoi(argv[5]);
	return (info);
}

void	init(int argc, char *argv[], t_philo **philos)
{
	t_info			*info;
	pthread_mutex_t	*m_porks;
	pthread_mutex_t	*m_locker;
	int				i;

	info = info_init(argc, argv);
	*philos = ft_calloc(info->number_to_philo, sizeof(t_philo));
	m_porks = malloc(sizeof(pthread_mutex_t) * (info->number_to_philo));
	m_locker = malloc(sizeof(pthread_mutex_t) * 2);
	i = -1;
	while (++i < info->number_to_philo)
	{
		(*philos)[i].info = info;
		(*philos)[i].my_pork = i;
		(*philos)[i].next_pork = i + 1;
		if (i == info->number_to_philo - 1)
			(*philos)[i].next_pork = 0;
		(*philos)[i].m_porks = m_porks;
		(*philos)[i].m_locker = m_locker;
		(*philos)[i].first_philo = *philos;
	}
}
