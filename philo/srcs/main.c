/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:42:24 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/14 11:57:54 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h" 

static int	arg_check(int argc)
{
	if (argc < 5)
	{
		printf("argc is too few\n");
		return (0);
	}
	else if (argc > 6)
	{
		printf("argc is too many\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_philo		*philos;
	int			i;

	if (!arg_check(argc))
		return (1);
	if (!init(argc, argv, &philos))
		return (1);
	philo_thread_init(philos);
	monitor_run(philos);
	i = -1;
	while (++i < philos[0].info->number_to_philo)
		pthread_detach(philos[i].tid);
	return (0);
}
