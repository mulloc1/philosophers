/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:04:52 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/14 11:31:18 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_free(t_philo *philos, pthread_mutex_t *m_forks, \
		pthread_mutex_t *m_printable, t_info *info)
{
	if (!philos)
	{
		free(info);
		return (1);
	}
	if (!m_forks)
	{
		free(info);
		free(philos);
		return (1);
	}
	if (!m_printable)
	{
		free(info);
		free(philos);
		free(m_forks);
		return (1);
	}
	return (0);
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
	if (init_free(*philos, m_forks, m_printable, info))
		return (0);
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
