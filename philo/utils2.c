/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:11:10 by jaebae            #+#    #+#             */
/*   Updated: 2022/05/10 23:24:22 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_handler(char *message, int exit_code)
{
	write(1, message, ft_strlen(message));
	exit(exit_code);
}

void	finished_eat_exit(t_philo *philo)
{
	ft_usleep(philo->info->number_to_philo * \
			(philo->info->philo_must_eat + 10));
	exit(0);
}
