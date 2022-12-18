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

void    ft_rra(t_stack **stack, int flag)
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
    if (flag)
        ft_putstr_fd("rra\n", 1);
}

void    ft_rrb(t_stack **stack, int flag)
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
    if (flag)
        ft_putstr_fd("rrb\n", 1);
}

void    ft_pb(t_stack **stack_a, t_stack **stack_b, int flag)
{
    t_stack *tmp;
    
    if (!*stack_b)
    {
        *stack_b = *stack_a;
        tmp = (*stack_a)->next;
        (*stack_a)->next = NULL;
        *stack_a = tmp;
        if (flag)
            ft_putstr_fd("pb\n", 1);
    }
    else if (!(*stack_a)->next)
    {
        (*stack_a)->next = *stack_b;
        *stack_b = *stack_a;
        *stack_a = NULL;
        if (flag)
            ft_putstr_fd("pb\n", 1);
    }
    else
    {
        tmp = (*stack_a)->next;
        (*stack_a)->next = *stack_b;
        *stack_b = *stack_a;
        *stack_a = tmp;
        if (flag)
            ft_putstr_fd("pb\n", 1);
    }
}

void    ft_pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (!*stack_a)
    {
        *stack_a = *stack_b;
        tmp = (*stack_b)->next;
        (*stack_b)->next = NULL;
        *stack_b = tmp;
        ft_putstr_fd("pa\n", 1);
    }
    else if (!(*stack_b)->next)
    {
        (*stack_b)->next = *stack_a;
        *stack_a = *stack_b;
        *stack_b = NULL;
        ft_putstr_fd("pb\n", 1);
    }
    else
    {
        tmp = (*stack_b)->next;
        (*stack_b)->next = *stack_a;
        *stack_a = *stack_b;
        *stack_b = tmp;
        ft_putstr_fd("pa\n", 1);
    }
}