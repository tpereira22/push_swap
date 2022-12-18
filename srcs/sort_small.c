/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:50:02 by timartin          #+#    #+#             */
/*   Updated: 2022/12/16 13:50:05 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void    sort_three(t_stack **stack)
{
    t_stack *mid;
    t_stack *down;

    mid = (*stack)->next;
    down = (*stack)->next->next;
    if ((*stack)->nbr > mid->nbr && down->nbr < mid->nbr)
    {
        ft_sa(stack);
        ft_rra(stack, 1);
    }
    if ((*stack)->nbr > mid->nbr && down->nbr > mid->nbr)
    {
        if ((*stack)->nbr > down->nbr)
            ft_ra(stack, 1);
        else if ((*stack)->nbr < down->nbr)
            ft_sa(stack);
    }
    if ((*stack)->nbr < mid->nbr && down->nbr < mid->nbr)
    {
        if ((*stack)->nbr > down->nbr)
            ft_rra(stack, 1);
        if ((*stack)->nbr < down->nbr)
        {
            ft_sa(stack);
            ft_ra(stack, 1);
        }
    }
}

void    sort_four_five(t_stack **stack_a, t_stack **stack_b, int len)
{
    if (len == 4)
        sort_four(stack_a, stack_b);
    else if (len == 5)
        sort_five(stack_a, stack_b);
}

void    sort_four(t_stack **stack_a, t_stack **stack_b)
{
    int small;
    int index;

    *stack_b = NULL;
    small = get_smallest(stack_a, &index);
    if (index <= 2)
    {
        while ((*stack_a)->nbr != small)
            ft_ra(stack_a, 1);
    }
    else
    {
        while ((*stack_a)->nbr != small)
            ft_rra(stack_a, 1);
    }
    ft_pb(stack_a, stack_b, 1);
    sort_three(stack_a);
    ft_pa(stack_a, stack_b);
}

void    sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int small;
    int index;
    int i;

    *stack_b = NULL;
    small = get_smallest(stack_a, &index);
    i = 2;
    while (i > 0)
    {
        if (index <= 3)
        {
            while ((*stack_a)->nbr != small)
                ft_ra(stack_a, 1);
        }
        else
        {
            while ((*stack_a)->nbr != small)
                ft_rra(stack_a, 1);
        }
        ft_pb(stack_a, stack_b, 1);
        small = get_smallest(stack_a, &index);
        i--;
    }
    sort_three(stack_a);
    ft_pa(stack_a, stack_b);
    ft_pa(stack_a, stack_b);
}    