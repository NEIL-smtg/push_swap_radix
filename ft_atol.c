/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:01:07 by suchua            #+#    #+#             */
/*   Updated: 2022/11/14 01:58:23 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_range(long num)
{
	return (num >= -2147483648 && num <= 2147483647);
}

long	ft_atol(char *str)
{
	int		sign;
	int		i;
	long	total;

	sign = 1;
	i = 0;
	total = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	if (check_range(total * sign))
		return (total * sign);
	else
		exit_now();
}
