/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:04:47 by timartin          #+#    #+#             */
/*   Updated: 2022/12/22 14:43:54 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	get_total_len(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		len;

	len = 0;
	tmp1 = *stack_a;
	tmp2 = *stack_b;
	while (tmp1)
	{
		len++;
		tmp1 = tmp1->next;
	}
	while (tmp2)
	{
		len++;
		tmp2 = tmp2->next;
	}
	return (len);
}

int	cut_calc(t_stack **stack_a, t_stack **stack_b, t_stack **tmp, int len)
{
	int	nbr_push;
	int	moves;
	int	best_moves;
	int	i;

	i = 0;
	best_moves = 0;
	nbr_push = 0;
	while (*tmp)
	{
		if ((i <= ((get_total_len(stack_a, stack_b) - len) / 2))
			|| (i >= (get_total_len(stack_a, stack_b)
					- (get_total_len(stack_a, stack_b) - len))) || len <= 100)
		{
			moves = calc_each_nbr(stack_a, stack_b, (*tmp)->nbr);
			if (best_moves > moves || i == 0)
			{
				best_moves = moves;
				nbr_push = (*tmp)->nbr;
			}
		}
		*tmp = (*tmp)->next;
		i++;
	}
	return (nbr_push);
}

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
