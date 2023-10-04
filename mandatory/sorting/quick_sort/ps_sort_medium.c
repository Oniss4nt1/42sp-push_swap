/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:24:11 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 16:52:54 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*copy_stack(t_node *head, t_stack *stack_k);
int		get_key_nbr(t_stack *stack_k, int key);

void	print_list(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	sort_medium(t_stack *stack)
{
	t_stack	*stack_k;
	int		key_nbr;
	int		i;

	i = 1;
	stack_k = init_stack();
	stack_k->head_a = copy_stack(stack->head_a, stack_k);
	stack_k->head_a = merge_sort(stack_k->head_a);
	while (i <= 4)
	{
		key_nbr = get_key_nbr(stack_k, i);
		move_elements(stack, key_nbr);
		i++;
	}
	while (stack->size_b > 0)
	{
		push_b_to_a(stack);
		if (stack->head_a->value > stack->head_a->next->value)
			swap(&stack->head_a, 'a', stack);
	}
	free_stack(stack_k);
}

t_node	*copy_stack(t_node *head, t_stack *stack_k)
{
	t_node	*new_head;
	t_node	*current;

	new_head = NULL;
	current = head;
	while (current)
	{
		add_to_list(&new_head, stack_k, current->value);
		current = current->next;
	}
	return (new_head);
}

int	get_key_nbr(t_stack *stack_k, int key)
{
	int		i;
	int		key_nbr;
	t_node	*current;

	i = 1;
	current = stack_k->head_a;
	while (current)
	{
		if (i == stack_k->size_a / 4 * key)
			key_nbr = current->value;
		i++;
		current = current->next;
	}
	return (key_nbr);
}

void	move_elements(t_stack *stack, int key_nbr)
{
	int	next_nbr;

	next_nbr = find_next_nbr(stack->head_a, key_nbr);
	while (next_nbr != 0 && !is_sorted(stack->head_a))
	{
		move_nbr_to_top(stack, next_nbr);
		push_a_to_b(stack);
		next_nbr = find_next_nbr(stack->head_a, key_nbr);
	}
}
