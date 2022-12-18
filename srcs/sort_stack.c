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

void    sort_small(t_stack **stack_a, t_stack **stack_b, int len)
{
    if (len == 2)
        ft_sa(stack_a);
    else if(len == 3)
        sort_three(stack_a);
    else
        sort_four_five(stack_a, stack_b, len);
}

void    calc_operations(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *dup_a;
    t_stack *dup_b;
    int nbr_push;

    dup_a = dup_list(stack_a);
    dup_b = dup_list(stack_b);
    nbr_push = calc_moves(&dup_a, &dup_b);
    sort_big(stack_a, stack_b, nbr_push);
    free_struct(&dup_a);
    free_struct(&dup_b);
}

void    last_rot_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int big;
    int rot_flag;

    tmp = *stack_b;
    rot_flag = 0;
    big = get_biggest(stack_b);
    calc_a(stack_b, big, &rot_flag);
    while (tmp->nbr != big)
    {
        if (rot_flag)
            ft_rb(stack_b, 1);
        else
            ft_rrb(stack_b, 1);
        tmp = tmp->next;
    }
    push_all_stack_a(stack_a, stack_b);
}

void    sort_stack(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *stack_b;
    int len;

    len = 0;
    tmp = *stack_a;
    stack_b = NULL;
    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }
    if (len < 6)
        sort_small(stack_a, &stack_b, len);
    else
    {
        ft_pb(stack_a, &stack_b, 1);
        ft_pb(stack_a, &stack_b, 1);
        while ((*stack_a)->next)
            calc_operations(stack_a, &stack_b);
        ft_pb(stack_a, &stack_b, 1);
    }
    last_rot_stack_b(stack_a, &stack_b);
    //print test stack_b
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
        ft_putstr_fd("\n\n", 1);
    }
    free_struct(&stack_b);
}