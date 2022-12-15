/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:50:15 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 17:50:20 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int check_dup_num(t_stack *stack)
{
    t_stack *tmp;

    while(stack)
    {
        //confirmar se intmax incluso ou nao
        if (stack->nbr >= 2147483647 || stack->nbr <= -2147483647)
            return (0);
        tmp = stack->next;
        while (tmp)
        {
            if (stack->nbr == tmp->nbr)
                return (0);
            tmp = tmp->next;
        }
        stack = stack->next;
    }
    return (1);
}

int	main(int ac, char **av)
{
    t_stack *stack_a;

	if (ac < 2)
        return (0);
    else
    {
        stack_a = check_args(ac, av);
        if (!stack_a || !check_dup_num(stack_a))
        {
            ft_putstr_fd("Error\n", 1);
            free_struct(&stack_a);
            exit (1);
        }
        //checkar if sorted antes de ir para sort
        if (!check_sort(stack_a))
            sort_stack(stack_a);
        while (stack_a->next)
        {
            ft_putnbr_fd(stack_a->nbr, 1);
            ft_putchar_fd(10, 1);
            stack_a = stack_a->next;
        }
        ft_putnbr_fd(stack_a->nbr, 1);
        ft_putchar_fd(10, 1);
    }

}