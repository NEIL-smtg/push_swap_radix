/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:46:09 by suchua            #+#    #+#             */
/*   Updated: 2022/11/14 01:59:10 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_now()
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	check_dup(t_stack **a, int num)
{
	t_stack	*tmp;

	if (!a || !*a)
		return (0);
	tmp = (*a);
	while (tmp)
	{
		if (num == tmp->data)
		{
			ft_clear_stack(a);
			exit_now();
		}
		tmp = tmp->next;
	}
	return (0);
}

t_stack	*ft_check_valid(char *av)
{
	int		i;
	int		num;
	t_stack	*s;

	i = 0;
	s = NULL;
	while (av[i])
	{
		if (ft_is_nb(&av[i]))
		{
			num = ft_atol(&av[i]);
			if (!check_dup(&s, num))
				stack_add_back(&s, ft_newstack(num));
			while (ft_is_nb(&av[i]))
				i++;
		}
		i++;
	}
	return (s);
}
