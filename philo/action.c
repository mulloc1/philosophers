/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 08:58:38 by jaebae            #+#    #+#             */
/*   Updated: 2022/04/28 13:33:24 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	long	current_time;

	current_time = time_stamp();
	if (current_time - philo->last_eat_time >= philo->info->time_to_die_m)
		died(philo);
	philo->last_eat_time = time_stamp();
	pthread_mutex_lock(&philo->m_locker[M_PRINTABLE]);
	printf("%ld %d has taken a pork\n%ld %d is eating\n", \
		current_time - philo->run_time, philo->my_pork, \
		current_time - philo->run_time, philo->my_pork);
	pthread_mutex_unlock(&philo->m_locker[M_PRINTABLE]);
	ft_usleep(philo->info->time_to_eat_u);
}

void	sleeping(t_philo *philo)
{
	long	current_time;

	current_time = time_stamp();
	if (current_time - philo->last_eat_time >= philo->info->time_to_die_m)
		died(philo);
	pthread_mutex_lock(&philo->m_locker[M_PRINTABLE]);
	printf("%ld %d is sleeping\n", \
			current_time - philo->run_time, philo->my_pork);
	pthread_mutex_unlock(&philo->m_locker[M_PRINTABLE]);
	ft_usleep(philo->info->time_to_sleep_u);
}

void	thinking(t_philo *philo)
{
	long	current_time;

	current_time = time_stamp();
	if (current_time - philo->last_eat_time >= philo->info->time_to_die_m)
		died(philo);
	pthread_mutex_lock(&philo->m_locker[M_PRINTABLE]);
	printf("%ld %d is thinking\n", \
			current_time - philo->run_time, philo->my_pork);
	pthread_mutex_unlock(&philo->m_locker[M_PRINTABLE]);
}

void	died(t_philo *philo)
{
	long	current_time;

	current_time = time_stamp();
	pthread_mutex_lock(&philo->m_locker[M_PRINTABLE]);
	printf("%ld %d is died\n", current_time - philo->run_time, philo->my_pork);
	exit(0);
	pthread_mutex_unlock(&philo->m_locker[M_PRINTABLE]);
}
