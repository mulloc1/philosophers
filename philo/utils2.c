/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:11:10 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/11 14:41:47 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	finished_eat_exit(t_philo *philo)
{
	ft_usleep(philo->info->number_to_philo * \
			(philo->info->philo_must_eat + 10));
}
