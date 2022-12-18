/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:17:32 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 18:17:54 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	ft_calc_ra(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int	swap;

	tmp1 = stack;
	tmp2 = stack->next;
	while(tmp1->next)
	{
		swap = tmp2->nbr;
		tmp2->nbr = tmp1->nbr;
		tmp1->nbr = swap;
		tmp2 = tmp2->next;
		tmp1 = tmp1->next;
	}
}

void    ft_calc_rra(t_stack *stack)
{
    t_stack *tmp;
    int i;

    tmp = stack;
    i = 0;
    while (stack->next)
    {
        stack = stack->next;
        i++;
    }
    stack->next = tmp;
    while (i > 1)
    {
        tmp = tmp->next;
        i--;
    }
    tmp->next = NULL;
}
