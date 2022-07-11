/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:26:47 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/11 18:26:47 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(&philo->m_forks[philo->left_fork]);
	pthread_mutex_lock(philo->m_printable);
	current_time = time_stamp();
	printf("%ld %d has taken a fork\n", current_time - \
			philo->run_time, philo->left_fork + 1);
	pthread_mutex_unlock(philo->m_printable);
	pthread_mutex_lock(&philo->m_forks[philo->right_fork]);
	pthread_mutex_lock(philo->m_printable);
	current_time = time_stamp();
	philo->last_eat_time = current_time;
	printf("%ld %d has taken a fork\n%ld %d is eating\n", \
		current_time - philo->run_time, philo->left_fork + 1, \
		current_time - philo->run_time, philo->left_fork + 1);
	pthread_mutex_unlock(philo->m_printable);
	ft_usleep(philo->info->time_to_eat_u);
	pthread_mutex_unlock(&philo->m_forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->m_forks[philo->left_fork]);
}

void	sleeping(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(philo->m_printable);
	current_time = time_stamp();
	printf("%ld %d is sleeping\n", \
			current_time - philo->run_time, philo->left_fork + 1);
	pthread_mutex_unlock(philo->m_printable);
	ft_usleep(philo->info->time_to_sleep_u);
}

void	thinking(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(philo->m_printable);
	current_time = time_stamp();
	printf("%ld %d is thinking\n", \
			current_time - philo->run_time, philo->left_fork + 1);
	pthread_mutex_unlock(philo->m_printable);
}

void	died(t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(philo->m_printable);
	current_time = time_stamp();
	printf("%ld %d died\n", \
			current_time - philo->run_time, philo->left_fork + 1);
}
