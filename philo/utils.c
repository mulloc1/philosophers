/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:01:30 by jaebae            #+#    #+#             */
/*   Updated: 2022/04/28 10:41:52 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	result = (void *)malloc(count * size);
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < count * size)
		((unsigned char *)result)[i] = 0;
	return (result);
}

long	time_stamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	time_stamp_u(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + (time.tv_usec));
}

void	ft_usleep(long time)
{
	long	goal_time;

	goal_time = time_stamp_u() + time;
	while (goal_time > time_stamp_u())
		usleep(100);
}
