/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:05:13 by jaebae            #+#    #+#             */
/*   Updated: 2022/04/28 09:05:14 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static size_t	ft_space_ch(const char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static char	ft_sign_ch(size_t *index, char chr)
{
	if (chr == '+')
	{
		(*index)++;
		return (1);
	}
	else if (chr == '-')
	{
		(*index)++;
		return (-1);
	}
	return (1);
}

static int	ft_is_overflow(long num, long add)
{
	if (num > LONG_MAX_H / 10)
		return (1);
	if (add > LONG_MAX_H - (num * 10))
		return (1);
	return (0);
}

static int	ft_is_underflow(long num, long add)
{
	if (num > LONG_MAX_H / 10)
		return (1);
	if (add > (LONG_MAX_H - (num * 10) + 1) && num != 0)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	size_t	i;
	char	sign;
	long	result;

	i = ft_space_ch(str);
	sign = ft_sign_ch(&i, str[i]);
	result = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (ft_is_overflow(result, str[i] - '0') && sign > 0)
			return (-1);
		else if (ft_is_underflow(result, str[i] - '0') && sign < 0)
			return (0);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return ((long)(result * sign));
}
