/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:17:32 by timartin          #+#    #+#             */
/*   Updated: 2022/12/22 14:06:53 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == '-'
			|| str[i] == '+' || str[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_matrix(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

t_stack	*list_str_arg(char *stack_list)
{
	int		i;
	int		nbr;
	char	**temp;
	t_stack	*stack_a;

	if (!check_num(stack_list))
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	stack_a = NULL;
	temp = ft_split(stack_list, 32);
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

t_stack	*check_args(int ac, char **av)
{
	t_stack	*stack_a;
	int		nbr;
	int		i;

	stack_a = NULL;
	i = 1;
	if (ac == 2)
		stack_a = list_str_arg(av[1]);
	else
	{
		while (i < ac)
		{
			if (!check_num(av[i]))
			{
				ft_putstr_fd("Error\n", 1);
				free_struct(&stack_a);
				exit(1);
			}
			nbr = ft_atoi(av[i]);
			add_back(&stack_a, new_entry(nbr));
			i++;
		}
	}
	return (stack_a);
}
