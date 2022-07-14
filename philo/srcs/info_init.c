/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:23:45 by jaebae            #+#    #+#             */
/*   Updated: 2022/07/14 11:47:17 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

static int	input_argv(int *member, char *argv, char *str)
{
	if (!is_numbers(argv))
	{
		printf("argv %s is not numbers\n", argv);
		return (0);
	}
	*member = ft_atoi(argv);
	if (!(*member))
	{
		printf("input_argv() ft_atoi() %s is zero\n", str);
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
	(*info)->time_to_eat_u = (*info)->time_to_eat_m * 1000;
	(*info)->time_to_sleep_u = (*info)->time_to_sleep_m * 1000;
	(*info)->philo_must_eat = -1;
	(*info)->is_processing = 1;
	if (argc == 6)
		if (!input_argv(&(*info)->philo_must_eat, argv[5], "philo_must_eat"))
			return (0);
	return (1);
}
