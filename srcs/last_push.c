/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:04:47 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 20:04:48 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int get_closest_big(t_stack **stack, int nbr)
{
    t_stack *tmp;
    int dif;
    int tmp_dif;
    int close;

    tmp = *stack;
    dif = 0;
    while (tmp)
    {
        tmp_dif = tmp->nbr - nbr;
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
        close = get_smallest(stack, &tmp_dif);
    return (close);
}

void    min_to_top(t_stack **stack_a)
{
    int small;
    int index;

    index = 0;
    small = get_smallest(stack_a, &index);
    while ((*stack_a)->nbr != small)
    {
        ft_ra(stack_a, 1);
    }
}

void    back_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int close;
    int rot_flag;

    close = 0;
    rot_flag = 0;
    while ((*stack_b)->next)
    {
        close = get_closest_big(stack_a, (*stack_b)->nbr);
        if ((*stack_a)->nbr != close)
        {
            calc_a(stack_a, close, &rot_flag);
            if (rot_flag)
                ft_ra(stack_a, 1);
            else
                ft_rra(stack_a, 1);
        }
        else
            ft_pa(stack_a, stack_b);
    }
    ft_pa(stack_a, stack_b);
    min_to_top(stack_a);
}