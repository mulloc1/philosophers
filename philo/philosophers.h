/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:02:40 by jaebae            #+#    #+#             */
/*   Updated: 2022/04/28 11:36:05 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

# define INT_MAX_H 2147483647
# define LONG_MAX_H 9223372036854775807
# define M_PRINTABLE 0
# define M_FINISHED_EAT 1

typedef struct s_info {
	int				number_to_philo;
	long			time_to_die_m;
	long			time_to_eat_m;
	long			time_to_sleep_m;
	long			time_to_die_u;
	long			time_to_eat_u;
	long			time_to_sleep_u;
	int				philo_must_eat;
}					t_info;

typedef struct s_philo {
	t_info				*info;
	pthread_t			tid;
	struct s_philo		*first_philo;
	long				run_time;
	long				last_eat_time;
	int					eat_cnt;
	int					my_fork;
	int					next_fork;
	pthread_mutex_t		*m_forks;
	pthread_mutex_t		*m_locker;
}				t_philo;

void	finished_eat_exit(t_philo *philo);
void	free_philo(t_philo *philo);
void	error_handler(char *message, int exit_code);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);
void	init(int argc, char *argv[], t_philo **philos);
void	*philo_run(void *ptr);
void	*monitor_run(void *ptr);
void	philo_thread_init(t_philo *philos);
long	time_stamp(void);
long	time_stamp_u(void);
void	ft_usleep(long time);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	died(t_philo *philo);

#endif
