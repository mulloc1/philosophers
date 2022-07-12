/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:42:24 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/12 09:34:37 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h" 

int	main(int argc, char *argv[])
{
	t_philo		*philos;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	init(argc, argv, &philos);
	philo_thread_init(philos);
	monitor_run(philos);
	i = -1;
	while (++i < philos[0].info->number_to_philo)
		pthread_detach(philos[i].tid);
	ft_usleep(500000);
	return (0);
}
