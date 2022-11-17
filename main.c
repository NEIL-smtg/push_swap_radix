/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:25:12 by suchua            #+#    #+#             */
/*   Updated: 2022/11/15 18:56:29 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	ft_printf("%6c\t%14c\n", 'a', 'b');
	while (a)
	{
		if (b)
			ft_printf("|%11d  |\t|%11d  |\n", a->data, b->data);
		else
			ft_printf("|%11d  |\t|%11c  |\n", a->data, 'n');
		a = a->next;
		if (b)
			b = b->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = ft_check_valid(ac, av);
		ft_sort(&stack_a, &stack_b);
		print_stack(stack_a, stack_b);
		ft_clear_stack(&stack_a);
		ft_clear_stack(&stack_b);
	}
	else
		exit_now();
	return (0);
}
