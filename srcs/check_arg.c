/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:17:32 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 18:17:54 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void    free_matrix(char **str)
{
    int i;

    if (!str)
        return ;
    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
}

t_stack *list_str_arg(char *stack)
{
    int i;
    int nbr;
    char    **temp;
    t_stack *stack_a;

    temp = ft_split(stack, 32);
    i = 0;
    while (temp[i])
    {
        nbr = ft_atoi(temp[i]);
        add_back(&stack_a, new_entry(nbr));
        i++;
    }
    free_matrix(temp);
    free(temp);
    return (stack_a);
}

t_stack *check_args(int ac, char **av)
{
    t_stack *stack_a;

    if (ac == 2)
        stack_a = list_str_arg(av[1]);
    else
    {  

    }
    return (stack_a);
}