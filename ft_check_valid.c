/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:46:09 by suchua            #+#    #+#             */
/*   Updated: 2022/11/15 14:56:13 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_now(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	check_range(long num)
{
	return (num >= -2147483648 && num <= 2147483647);
}

int	check_dup(t_stack **a)
{
	int		ans;
	t_stack	*tmp;

	ans = 0;
	tmp = (*a);
	while (tmp)
	{
		ans ^= tmp->data;
		tmp = tmp->next;
	}
	return (ans);
}

t_stack	*more_than_2av(char **av)
{
	t_stack	*s;
	int		i;
	long	num;

	i = 0;
	s = NULL;
	while (av[++i])
	{
		num = my_atoi(av[i]);
		if (!ft_is_nb(av[i]) || !check_range(num) || check_dup(&s, num))
			exit_now();
		stack_add_back(&s, ft_newstack(num));
	}
	return (s);
}

t_stack	*ft_check_valid(int ac, char **av)
{
	int		i;
	long	num;
	t_stack	*s;

	i = 0;
	s = NULL;
	if (ac > 2)
		return (more_than_2av(av));
	while (av[1][i])
	{
		if (ft_is_nb(&av[1][i]))
		{
			num = my_atoi(&av[1][i]);
			if (!check_range(num) || check_dup(&s, num))
				exit_now();
			stack_add_back(&s, ft_newstack(num));
			while (ft_is_nb(&av[1][i]))
				i++;
		}
		else
			i++;
	}
	if (!s->next)
		exit_now();
	return (s);
}
