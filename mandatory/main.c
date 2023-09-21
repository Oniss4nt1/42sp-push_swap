/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:55:27 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/21 18:39:41 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "/nfs/homes/brunrodr/08.PUSH_SWAP/42sp-push_swap/libft/src/ft_strlen.c"
// #include <stdio.h>
#include "push_swap.h"

//Function

// int main(void)
// {
// 	printf("%zu", ft_strlen("teste"));
	
// 	return (0);
// }


// int main(int argc, char *argv[])
// {
// 	t_stack *stack;
	
// 	ft_printf("teste");
// 	if (argc < 2)
// 	{
// 		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
// 		return (1);
// 	}
// 	stack = init_stack();
// 	if (!process_arguments(stack, argc, argv))
// 	{
// 		free_stack(stack);
// 		return (1);
// 	}
// 	if (is_sorted(stack->head_a))
// 	{
// 		ft_putstr_fd("Error\nList is already sorted\n", 2);
// 		free_stack(stack);
// 		return (1);
// 	}
// 	// rotate_a(stack);
// 	// swap_a(stack);
// 	push_b(stack);
// 	push_b(stack);
// 	push_b(stack);
// 	rotate_b(stack);
// 	push_a(stack);
// 	ft_printf("Stack B:\n");
// 	while (stack->head_b)
// 	{
// 		// ft_putnbr_fd(stack->head_a->value, 1);
// 		// ft_putchar_fd('\n', 1);
// 		// stack->head_a = stack->head_a->next;
// 		ft_putnbr_fd(stack->head_b->value, 1);
// 		ft_putchar_fd('\n', 1);
// 		stack->head_b = stack->head_b->next;
// 	}
// 	ft_printf("End of stack B\n");
// 	ft_printf("Stack A:\n");
// 	while (stack->head_a)
// 	{
// 		ft_putnbr_fd(stack->head_a->value, 1);
// 		ft_putchar_fd('\n', 1);
// 		stack->head_a = stack->head_a->next;
// 	}
// 	ft_printf("End of stack A\n");

// 	reverse_rr(stack);
// 	ft_printf("Stack B:\n");
// 	while (stack->head_b)
// 	{
// 		ft_putnbr_fd(stack->head_b->value, 1);
// 		ft_putchar_fd('\n', 1);
// 		stack->head_b = stack->head_b->next;
// 	}
// 	ft_printf("End of stack B\n");
// 	ft_printf("Stack A:\n");
// 	while (stack->head_a)
// 	{
// 		ft_putnbr_fd(stack->head_a->value, 1);
// 		ft_putchar_fd('\n', 1);
// 		stack->head_a = stack->head_a->next;
// 	}
// 	ft_printf("End of stack A\n");

	
// 	free_stack(stack);
// 	return (0);	
// }
