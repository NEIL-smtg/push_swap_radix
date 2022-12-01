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

int	good_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_is_nb(&s[i]))
		i++;
	if (!s[i])
		return (1);
	return (0);
}

int	is_positive(long nb)
{
	if (nb >= 0)
		return (1);
	return (-1);
}

t_stack	*more_than_2av(char **av)
{
	long	num;
	int		i;
	t_stack	*s;

	i = 0;
	s = NULL;
	while (av[++i])
	{
		num = my_atoi(av[i]);
		if (!good_str(av[i]) || !check_range(num) || check_dup(&s, num))
		{
			ft_clear_stack(&s);
			exit_now();
		}
		stack_add_back(&s, ft_newstack(num, is_positive(num)));
	}
	if (get_stack_size(s) <= 1)
	{
		ft_clear_stack(&s);
		exit_now();
	}
	return (s);
}

t_stack	*ft_check_valid(int ac, char **av)
{
	if (ac >= 2)
		return (more_than_2av(av));
	return (NULL);
}
