/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:04:47 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 20:04:48 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int get_biggest(t_stack **stack)
{
    t_stack *tmp;
    int big;

    tmp = *stack;
    big = (*stack)->nbr;
    while (tmp)
    {
        if (tmp->nbr > big)
           big = tmp->nbr;
        tmp = tmp->next;
    }
    return (big);
}

int get_closest_small(t_stack **stack, int nbr)
{
    t_stack *tmp;
    int dif;
    int tmp_dif;
    int close;

    tmp = *stack;
    dif = 0;
    while (tmp)
    {
        tmp_dif = nbr - tmp->nbr;
        if (dif < 0)
            dif = 0;
        if ((tmp_dif < dif && tmp_dif > 0) || dif == 0)
        {
            dif = tmp_dif;
            close = tmp->nbr;
        }
        tmp = tmp->next;
    }
    if (dif <= 0)
        close = get_biggest(stack);
    return (close);
}

int get_smallest(t_stack **stack, int *index)
{
    t_stack *tmp;
    int small;
    int pos_i;

    tmp = *stack;
    pos_i = 0;
    *index = 0;
    small = (*stack)->nbr;
    while (tmp)
    {
        pos_i++;
        if (tmp->nbr < small)
        {
            *index = pos_i;
            small = tmp->nbr;
        }
        tmp = tmp->next;
    }
    return (small);
}

t_stack *dup_list(t_stack **stack)
{
    t_stack *dup;
    t_stack *tmp;

    tmp = *stack;
    dup = new_entry(tmp->nbr);
    tmp = tmp->next;
    while (tmp)
    {
        add_back(&dup, new_entry(tmp->nbr));
        tmp = tmp->next;
    }
    return(dup);
}