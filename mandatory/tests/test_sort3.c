/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:41:58 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/22 18:19:17 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *stack;
	
	if (argc < 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	stack = init_stack();
	if (!process_arguments(stack, argc, argv))
	{
		free_stack(stack);
		return (1);
	}
	if (is_sorted(stack->head_a))
	{
		ft_putstr_fd("Error\nList is already sorted\n", 2);
		free_stack(stack);
		return (1);
	}

	
	ft_printf("Stack B:\n");
	push_a_to_b(stack);
	push_a_to_b(stack);
	push_a_to_b(stack);
	
	sort_three(&stack->head_b);
	while (stack->head_b)
	{
		ft_putnbr_fd(stack->head_b->value, 1);
		ft_putchar_fd('\n', 1);
		stack->head_b = stack->head_b->next;
	}
	ft_printf("End of stack B\n");


	free_stack(stack);
	return (0);	
}
