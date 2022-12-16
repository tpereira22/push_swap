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

void    sort_small(t_stack **stack, int len)
{
    if (len == 2)
        ft_sa(stack);
    else if(len == 3)
        sort_three(stack);
    else if (len <= 5)
        sort_four_five(stack, len);

}

void    sort_stack(t_stack **stack)
{
    t_stack *tmp;
    int len;

    len = 0;
    tmp = *stack;
    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }
    if (len <= 6)
        sort_small(stack, len);
    // else
    //     sort_small(stack, len);
}