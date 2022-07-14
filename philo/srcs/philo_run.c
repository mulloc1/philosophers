/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:34:11 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/14 12:52:50 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_run(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->left_fork % 2 == 1)
		ft_usleep(philo->info->time_to_eat_u);
	while (philo->info->is_processing)
	{
		eating(philo);
		if (++philo->eat_cnt == philo->info->philo_must_eat)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
