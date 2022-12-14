/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:51:05 by timartin          #+#    #+#             */
/*   Updated: 2022/12/22 15:38:34 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

//push_swap.c
int		check_dup_num(t_stack *stack);
int		get_stack_len(t_stack **stack);

//check_arg.c
t_stack	*check_args(int ac, char **av);
t_stack	*list_str_arg(char *stack);
void	free_matrix(char **str);
int		check_num(char *str);

//struct_utils.c
t_stack	*new_entry(int content);
t_stack	*lst_last(t_stack *stack);
void	add_back(t_stack **stack, t_stack *new);
void	free_struct(t_stack **stack);

//push_swap_utils.c
int		get_smallest(t_stack **stack, int *index);
int		get_closest_small(t_stack **stack, int nbr);
t_stack	*dup_list(t_stack **stack);
int		get_biggest(t_stack **stack);

//push_swap_utils2.c
int		check_sort(t_stack *stack);
void	push_all_stack_a(t_stack **stack_a, t_stack **stack_b);
int		cut_calc(t_stack **stack_a, t_stack **stack_b, t_stack **tmp, int len);
int		get_total_len(t_stack **stack_a, t_stack **stack_b);

//push_swap_utils3.c
void	rot_util_up(t_stack **stack_a, t_stack **stack_b,
			int rotate_a, int rotate_b);
void	rot_util_down(t_stack **stack_a, t_stack **stack_b,
			int rotate_a, int rotate_b);
void	pb_util(t_stack **stack_a, t_stack **stack_b, t_stack **tmp);
void	sort_small_util(t_stack **stack, t_stack **down);

//sort_stack.c
void	sort_stack(t_stack **stack_a);
void	sort_small(t_stack **stack_a, t_stack **stack_b, int len);
void	calc_operations(t_stack **stack_a, t_stack **stack_b, int len);

//sort_small.c
void	sort_three(t_stack **stack);
void	sort_four_five(t_stack **stack_a, t_stack **stack_b, int len);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

//sort_big.c
void	sort_big(t_stack **stack_a, t_stack **stack_b, int nbr_push);
void	rot_a(t_stack **stack, int nbr_push, int rot_flag);
void	rot_b(t_stack **stack, int nbr_push, int rot_flag);
void	rot_both(t_stack **stack_a, t_stack **stack_b, int nbr_push);

//last_push.c
void	back_to_a(t_stack **stack_a, t_stack **stack_b);
int		get_closest_big(t_stack **stack, int nbr);
void	min_to_top(t_stack **stack_a);
int		calc_util(t_stack **tmp, int nbr_to_find);

//calculations.c
int		calc_moves(t_stack **stack_a, t_stack **stack_b, int len);
int		calc_each_nbr(t_stack **stack_a, t_stack **stack_b, int nbr);
int		calc_a(t_stack **stack_a, int nbr, int *rot_flag);
int		calc_b(t_stack **stack_b, int nbr, int *rot_flag);

//operations.c
void	ft_sa(t_stack **stack);
void	ft_ra(t_stack **stack, int flag);
void	ft_rb(t_stack **stack, int flag);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

//operations2.c
void	ft_rra(t_stack **stack, int flag);
void	ft_rrb(t_stack **stack, int flag);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int flag);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);

//operations3.c
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
