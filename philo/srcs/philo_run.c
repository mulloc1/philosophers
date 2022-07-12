/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:34:11 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/12 09:34:35 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_run(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->info->number_to_philo == 1)
		ft_usleep(philo->info->time_to_eat_u * 2);
	if (philo->left_fork % 2 == 0)
		ft_usleep(philo->info->time_to_eat_u);
	while (philo->info->is_processing)
	{
		eating(philo);
		sleeping(philo);
		if (++philo->eat_cnt == philo->info->philo_must_eat)
			break ;
		thinking(philo);
	}
	return (NULL);
}
