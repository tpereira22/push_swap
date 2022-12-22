/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:50:15 by timartin          #+#    #+#             */
/*   Updated: 2022/12/22 14:37:43 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	rot_util_up(t_stack **stack_a, t_stack **stack_b,
int rotate_a, int rotate_b)
{
	if (rotate_a > rotate_b)
	{
		while (rotate_b > 0)
		{
			ft_rr(stack_a, stack_b);
			rotate_a--;
			rotate_b--;
		}
		while (rotate_a-- > 0)
			ft_ra(stack_a, 1);
	}
	else
	{
		while (rotate_a > 0)
		{
			ft_rr(stack_a, stack_b);
			rotate_a--;
			rotate_b--;
		}
		while (rotate_b-- > 0)
			ft_rb(stack_b, 1);
	}
}

void	rot_util_down(t_stack **stack_a, t_stack **stack_b,
int rotate_a, int rotate_b)
{
	if (rotate_a > rotate_b)
	{
		while (rotate_b > 0)
		{
			ft_rrr(stack_a, stack_b);
			rotate_a--;
			rotate_b--;
		}
		while (rotate_a-- > 0)
			ft_rra(stack_a, 1);
	}
	else
	{
		while (rotate_a > 0)
		{
			ft_rrr(stack_a, stack_b);
			rotate_a--;
			rotate_b--;
		}
		while (rotate_b-- > 0)
			ft_rrb(stack_b, 1);
	}
}

void	pb_util(t_stack **stack_a, t_stack **stack_b, t_stack **tmp)
{
	*stack_b = *stack_a;
	*tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = *tmp;
}

void	sort_small_util(t_stack **stack, t_stack **down)
{		
	if ((*stack)->nbr > (*down)->nbr)
		ft_rra(stack, 1);
	if ((*stack)->nbr < (*down)->nbr)
	{
		ft_sa(stack);
		ft_ra(stack, 1);
	}
}
