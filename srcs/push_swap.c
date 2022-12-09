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

int	main(int ac, char **av)
{
    t_stack *stack_a;

	if (ac < 2)
        return (0);
    else
    {
        stack_a = check_args(ac, av);
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