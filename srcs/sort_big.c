/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:50:15 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 17:50:20 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

//return 1 if ra/rb
//return 0 if rra/rrb
void    rot_b(t_stack **stack, int nbr_push, int rot_flag)
{
    int close;

    close = get_closest_small(stack, nbr_push);
    if (rot_flag)
    {
        while ((*stack)->nbr != close)
            ft_rb(stack, 1);
    }
    else
    {
        while ((*stack)->nbr != close)
            ft_rrb(stack, 1);
    }
}

void    rot_a(t_stack **stack, int nbr_push, int rot_flag)
{
    if (rot_flag)
    {
        while ((*stack)->nbr != nbr_push)
            ft_ra(stack, 1);
    }
    else
    {
         while ((*stack)->nbr != nbr_push)
            ft_rra(stack, 1);
    }
}

void    rot_both(t_stack **stack_a, t_stack **stack_b, int nbr_push)
{
    int rotate_a;
    int rotate_b;
    int rot_flag;

    rot_flag = 0;
    rotate_a = calc_a(stack_a, nbr_push, &rot_flag);
    rotate_b = calc_b(stack_b, nbr_push, &rot_flag);
    if (rotate_a > rotate_b)
    {
        while (rotate_b > 0)
        {
            if (rot_flag)
                ft_rr(stack_a, stack_b);
            else
                ft_rrr(stack_a, stack_b);
            rotate_a--;
            rotate_b--;
        }
        while (rotate_a > 0)
        {
            if (rot_flag)
                ft_ra(stack_a, 1);
            else
                ft_rra(stack_a, 1);
            rotate_a--;
        }
    }
    else
    {
        while (rotate_a > 0)
        {
            if (rot_flag)
                ft_rr(stack_a, stack_b);
            else
                ft_rrr(stack_a, stack_b);
            rotate_a--;
            rotate_b--;
        }
        while (rotate_b > 0)
        {
            if (rot_flag)
                ft_rb(stack_b, 1);
            else
                ft_rrb(stack_b, 1);
            rotate_b--;
        }
    }
}

void    sort_big(t_stack **stack_a, t_stack **stack_b, int nbr_push)
{
    int rotate_a;
    int rotate_b;
    int rot_flag_a;
    int rot_flag_b;

    rot_flag_a = 0;
    rot_flag_b = 0;
    rotate_a = calc_a(stack_a, nbr_push, &rot_flag_a);
    rotate_b = calc_b(stack_b, nbr_push, &rot_flag_b);
    if (rotate_a == 0 && rotate_b == 0)
        ft_pb(stack_a, stack_b, 1);
    else if (rotate_a != 0 && rotate_b == 0)
        rot_a(stack_a, nbr_push, rot_flag_a);
    else if (rotate_a == 0 && rotate_b != 0)
        rot_b(stack_b, nbr_push, rot_flag_b);
    else
    {
        if (rot_flag_a == rot_flag_b)
            rot_both(stack_a, stack_b, nbr_push);
        else
        {
            rot_a(stack_a, nbr_push, rot_flag_a);
            rot_b(stack_b, nbr_push, rot_flag_b);
        }
    }
    //printf("nr_push - %d\n", nbr_push);
    ft_pb(stack_a, stack_b, 1);
    //printf("r_a - %d | r_b - %d - nbr - %d | r_f_a - %d | r_f_b - %d\n", rotate_a, rotate_b, nbr_push, rot_flag_a, rot_flag_b);
}