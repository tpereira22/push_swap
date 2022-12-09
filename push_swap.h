/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:51:05 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 17:51:06 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "../libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	long	nbr;
	struct s_stack	*next;
}	t_stack;

//check_arg.c
t_stack	*check_args(int ac, char **av);
t_stack *list_str_arg(char *stack);

//struct_utils.c
t_stack *new_entry(int content);
t_stack *lst_last(t_stack *stack);
void    add_back(t_stack **stack, t_stack *new);


//error.c
void    error_msg(void);

//push_swap_utils.c

#endif