/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:04:47 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 20:04:48 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int sort_three(t_stack *stack)
{
    (void)stack;
    return (0);
}

void    sort_stack(t_stack *stack)
{
    int len;

    len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    if (len == 3)
        sort_three(stack)
}