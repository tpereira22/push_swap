/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:40:46 by timartin          #+#    #+#             */
/*   Updated: 2022/12/16 12:40:49 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void    ft_sa(t_stack **stack)
{
	t_stack	*tmp;
	int	swap;

	tmp = (*stack)->next;
	swap = tmp->nbr;
	tmp->nbr = (*stack)->nbr;
	(*stack)->nbr = swap;
	ft_putstr_fd("sa\n", 1);
}

void	ft_ra(t_stack **stack, int flag)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int	swap;

	tmp1 = *stack;
	tmp2 = (*stack)->next;
	while(tmp1->next)
	{
		swap = tmp2->nbr;
		tmp2->nbr = tmp1->nbr;
		tmp1->nbr = swap;
		tmp2 = tmp2->next;
		tmp1 = tmp1->next;
	}
	if (flag)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **stack, int flag)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int	swap;

	tmp1 = *stack;
	tmp2 = (*stack)->next;
	while(tmp1->next)
	{
		swap = tmp2->nbr;
		tmp2->nbr = tmp1->nbr;
		tmp1->nbr = swap;
		tmp2 = tmp2->next;
		tmp1 = tmp1->next;
	}
	if (flag)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}