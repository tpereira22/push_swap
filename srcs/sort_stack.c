/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:04:47 by timartin          #+#    #+#             */
/*   Updated: 2022/12/22 14:26:53 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	sort_small(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len == 2)
		ft_sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else
		sort_four_five(stack_a, stack_b, len);
}

void	calc_operations(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*dup_a;
	t_stack	*dup_b;
	int		nbr_push;

	dup_a = dup_list(stack_a);
	dup_b = dup_list(stack_b);
	nbr_push = calc_moves(&dup_a, &dup_b, len);
	free_struct(&dup_a);
	free_struct(&dup_b);
	sort_big(stack_a, stack_b, nbr_push);
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*stack_b;
	int		len;

	len = 0;
	tmp = *stack_a;
	stack_b = NULL;
	len = get_stack_len(&tmp);
	if (len < 6)
		sort_small(stack_a, &stack_b, len);
	else
	{
		ft_pb(stack_a, &stack_b, 1);
		ft_pb(stack_a, &stack_b, 1);
		while ((*stack_a)->next && get_stack_len(stack_a) > 3)
		{
			calc_operations(stack_a, &stack_b, (len - 2));
			len--;
		}
		sort_three(stack_a);
		back_to_a(stack_a, &stack_b);
	}
	free_struct(&stack_b);
}
