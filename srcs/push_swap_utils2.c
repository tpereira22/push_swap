/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:04:47 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 20:04:48 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int cut_calc(t_stack **stack_a, t_stack **stack_b, t_stack **tmp, int len)
{
    int i;
    int moves;
    int best_moves;
    int nbr_push;

    best_moves = 0;
    moves = 0;
    nbr_push = 0;
    i = len - 50;
    if (len > 100)
    {
        while (*tmp)
        {
            if (i > len)
                return (nbr_push);
            moves = calc_each_nbr(stack_a, stack_b, (*tmp)->nbr);
            if (best_moves > moves || nbr_push == 0)
            {
                best_moves = moves;
                nbr_push = (*tmp)->nbr;
            }
            *tmp = (*tmp)->next;
            i++;
        }
    } 
    else
    {
        while (*tmp)
        {
            moves = calc_each_nbr(stack_a, stack_b, (*tmp)->nbr);
            if (best_moves > moves || nbr_push == 0)
            {
                best_moves = moves;
                nbr_push = (*tmp)->nbr;
            }
            *tmp = (*tmp)->next;
        }
    }
    return (nbr_push);
}

void    push_all_stack_a(t_stack **stack_a, t_stack **stack_b)
{
    while ((*stack_b)->next)
        ft_pa(stack_a, stack_b);
    ft_pa(stack_a, stack_b);
}

int check_sort(t_stack *stack)
{  
    int tmp;

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