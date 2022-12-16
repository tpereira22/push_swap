/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:53:58 by timartin          #+#    #+#             */
/*   Updated: 2022/12/16 13:53:59 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void    ft_rra(t_stack **stack)
{
    t_stack *tmp;
    int i;

    tmp = *stack;
    i = 0;
    while ((*stack)->next)
    {
        *stack = (*stack)->next;
        i++;
    }
    (*stack)->next = tmp;
    while (i > 1)
    {
        tmp = tmp->next;
        i--;
    }
    tmp->next = NULL;
    ft_putstr_fd("rra\n", 1);
}

void    ft_pb(t_stack **stack_a, t_stack **stack_b)
{
    (void)stack_a;
    (void)stack_b;
}