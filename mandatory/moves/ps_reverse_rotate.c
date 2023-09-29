/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:07:31 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/29 18:27:04 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_node **head, char move, t_stack *stack)
{
	t_node *last;
	t_node *penultimate;

	if (!*head || !(*head)->next)
		return ;
	penultimate = NULL;
	last = *head;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
 	last->next = *head;
	*head = last;

	if (move == 'a')
	{
		ft_printf("rra\n");
		stack->moves++; //TODO: remove this line
	}
	else if (move == 'b')
	{
		ft_printf("rrb\n");
		stack->moves++; //TODO: remove this line
	}
	else if (move == 'r')
	{
		ft_printf("rrr\n");
		stack->moves++; //TODO: remove this line
	}
	print_stacks(stack);
	
}

void	double_reverse_rr(t_stack *stack)
{
	reverse_rotate(&stack->head_a, 'r', stack);
	reverse_rotate(&stack->head_b, 'r', stack);
}