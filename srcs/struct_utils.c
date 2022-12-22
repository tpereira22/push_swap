/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:32:30 by timartin          #+#    #+#             */
/*   Updated: 2022/12/22 14:26:18 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	free_struct(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = tmp;
	}
}

t_stack	*lst_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = (stack)->next;
	return (stack);
}

void	add_back(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
		(lst_last(*stack))->next = new;
}

t_stack	*new_entry(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_putstr_fd("Error\n", 1);
	new->nbr = content;
	new->next = NULL;
	return (new);
}
