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

void    sort_four_five(t_stack **stack_a, int len)
{
    if (len == 4)
        sort_four(stack_a);
    else if (len == 5)
        sort_five(stack_a);
}

void    sort_four(t_stack **stack_a)
{
    t_stack *stack_b;
    //t_stack *tmp;
    int small;
    int pos;

    stack_b = NULL;
    small = get_smallest(stack_a, &pos);
    if (pos <= 2)
    {
        while ((*stack_a)->nbr != small)
            ft_ra(stack_a);
    }
    else
    {
        while ((*stack_a)->nbr != small)
            ft_rra(stack_a);
    }
    ft_pb(stack_a, &stack_b);
    //print_test stack_b
    if (stack_b)
    {
        while (stack_b->next)
        {
            ft_putnbr_fd(stack_b->nbr, 1);
            ft_putchar_fd(10, 1);
            stack_b = stack_b->next;
        }
        ft_putnbr_fd(stack_b->nbr, 1);
        ft_putchar_fd(10, 1);
    }
}

void    sort_five(t_stack **stack_a)
{
    (void)stack_a;
}

void    sort_three(t_stack **stack)
{
    t_stack *mid;
    t_stack *down;

    mid = (*stack)->next;
    down = (*stack)->next->next;
    if ((*stack)->nbr > mid->nbr && down->nbr < mid->nbr)
    {
        ft_sa(stack);
        ft_rra(stack);
    }
    if((*stack)->nbr > mid->nbr && down->nbr > mid->nbr)
    {
        if ((*stack)->nbr > down->nbr)
            ft_ra(stack);
        else if ((*stack)->nbr < down->nbr)
            ft_sa(stack);
    }
    if((*stack)->nbr < mid->nbr && down->nbr < mid->nbr)
    {
        if ((*stack)->nbr > down->nbr)
            ft_rra(stack);
        if ((*stack)->nbr < down->nbr)
        {
            ft_sa(stack);
            ft_ra(stack);
        }
    }
}