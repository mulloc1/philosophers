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

int	is_numbers(char *str)
{
	int	i;

	i =  -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

int	input_argv(int *member, char *argv, char *str)
{
	if (!is_numbers(argv))
	{
		printf("argv is not numbers\n");
		return (0);
	}
	*member = ft_atoi(argv);
	if (!(*member))
	{
		printf("input_argv ft_atoi %s is zero\n", str);
		return (0);
	}
	return (1);
}

int	info_init(int argc, char *argv[], t_info **info)
{	
	*info = malloc(sizeof(t_info));
	if (!(*info))
		return (0);
	if (!input_argv(&(*info)->number_to_philo, argv[1], "number_to_philo"))
		return (0);
	if (!input_argv(&(*info)->time_to_die_m, argv[2], "time_to_die"))
		return (0);
	if (!input_argv(&(*info)->time_to_eat_m, argv[3], "time_to_eat"))
		return (0);
	if (!input_argv(&(*info)->time_to_sleep_m, argv[4], "time_to_sleep"))
		return (0);
	(*info)->time_to_die_u = (*info)->time_to_die_m * 1000;
	(*info)->time_to_eat_u= (*info)->time_to_eat_m * 1000;
	(*info)->time_to_sleep_u = (*info)->time_to_sleep_m * 1000;
	(*info)->philo_must_eat = -1;
	(*info)->is_processing = 1;
	if (argc == 6)
		if (!input_argv(&(*info)->philo_must_eat, argv[5], "philo_must_eat"))
			return (0);
	return (1);
}

int	init_free(t_philo *philos, pthread_mutex_t *m_forks, pthread_mutex_t *m_printable)
{
	if (!philos)
	{
		free(philos);
		return (0);
	}
	if (!m_forks)
	{
		free(m_forks);
		return (0);
	}
	if (!m_printable)
	{
		free(m_printable);
		return (0);
	}
	return (1);
}

int	init(int argc, char *argv[], t_philo **philos)
{
	t_info			*info;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	*m_printable;
	int				i;

	if (!info_init(argc, argv, &info))
		return (0);
	*philos = ft_calloc(info->number_to_philo, sizeof(t_philo));
	m_forks = malloc(sizeof(pthread_mutex_t) * (info->number_to_philo));
	m_printable = malloc(sizeof(pthread_mutex_t));
	if (!init_free(*philos, m_forks, m_printable))
	{
		free(info);
		return (0);
	}
	i = -1;
	while (++i < info->number_to_philo)
	{
		(*philos)[i].info = info;
		(*philos)[i].left_fork = i;
		(*philos)[i].right_fork = (i + 1) % info->number_to_philo;
		(*philos)[i].m_forks = m_forks;
		(*philos)[i].m_printable = m_printable;
	}
	return (1);
}
