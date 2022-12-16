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

int get_smallest(t_stack **stack, int *pos)
{
    t_stack *tmp;
    int small;
    int pos_i;

    tmp = *stack;
    pos_i = 0;
    *pos = 0;
    small = (*stack)->nbr;
    while (tmp)
    {
        pos_i++;
        if (tmp->nbr < small)
        {
            *pos = pos_i;
            small = tmp->nbr;
        }
        tmp = tmp->next;
    }
    return (small);
}