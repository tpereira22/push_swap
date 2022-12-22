/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:04:47 by timartin          #+#    #+#             */
/*   Updated: 2022/12/22 14:37:19 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	push_all_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->next)
		ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

int	check_sort(t_stack *stack)
{
	int	tmp;

	tmp = stack->nbr;
	stack = stack->next;
	while (stack)
	{
		if (tmp > stack->nbr)
			return (0);
		tmp = stack->nbr;
		stack = stack->next;
	}
	return (1);
}
