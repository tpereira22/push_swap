/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:17:32 by timartin          #+#    #+#             */
/*   Updated: 2022/12/09 18:17:54 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	calc_b(t_stack **stack_b, int nbr, int *rot_flag)
{
	t_stack	*tmp;
	int		moves;
	int		tmp_moves;
	int		close;

	tmp = dup_list(stack_b);
	close = get_closest_small(stack_b, nbr);
	tmp_moves = 0;
	while (tmp->nbr != close)
	{
		ft_ra(&tmp, 0);
		tmp_moves++;
	}
	free_struct(&tmp);
	tmp = dup_list(stack_b);
	*rot_flag = 1;
	moves = tmp_moves;
	tmp_moves = 0;
	while (tmp->nbr != close)
	{
		ft_rra(&tmp, 0);
		tmp_moves++;
	}
	if (moves > tmp_moves)
	{
		*rot_flag = 0;
		moves = tmp_moves;
	}
	free_struct(&tmp);
	return (moves);
}

int	calc_a(t_stack **stack_a, int nbr, int *rot_flag)
{
	t_stack	*tmp;
	int	moves;
	int	tmp_moves;
    
	tmp = dup_list(stack_a);
	tmp_moves = 0;
	while (tmp->nbr != nbr)
	{
		ft_ra(&tmp, 0);
		tmp_moves++;
	}
	free_struct(&tmp);
	tmp = dup_list(stack_a);
	*rot_flag = 1;
	moves = tmp_moves;
	tmp_moves = 0;
	while (tmp->nbr != nbr)
	{
		ft_rra(&tmp, 0);
		tmp_moves++;
	}
	if (moves > tmp_moves)
	{
		*rot_flag = 0;
		moves = tmp_moves;
	}
	free_struct(&tmp);
	return(moves);
}

int	calc_each_nbr(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	moves_a;
	int	moves_b;
	int	total_moves;
	int	flag;

	flag = 0;
	moves_a = calc_a(stack_a, nbr, &flag);
	moves_b = calc_b(stack_b, nbr, &flag);
	total_moves = moves_a + moves_b;
	moves_b = flag;
	moves_a = calc_a(stack_a, nbr, &flag);
	if (moves_b == flag)
	{
		moves_b = calc_b(stack_b, nbr, &flag);
		if (moves_a > moves_b)
			total_moves = moves_a;
		else
			total_moves = moves_b; 
	}
	return (total_moves);
}

int	calc_moves(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*tmp;
	int		nbr_push;

	//tmp = dup_list(stack_a);
	tmp = *stack_a;
	nbr_push = cut_calc(stack_a, stack_b, &tmp, len);
	//free_struct(&tmp);
	return (nbr_push);
}
