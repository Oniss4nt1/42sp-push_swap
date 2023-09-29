/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:24:11 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/29 16:22:25 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *copy_stack(t_node *head, t_stack *stack_k);
int	get_key_nbr(t_stack *stack_k, int key);

void	print_list(t_node *head)
{
	t_node *temp;

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
	t_stack *stack_k;
	int	key_nbr;
	int i;

	i = 1;
	stack_k = init_stack();
	stack_k->head_a = copy_stack(stack->head_a, stack_k); // Function to copy stack A
	stack_k->head_a = merge_sort(stack_k->head_a); // Function to sort stack A
	// print_list(stack_k->head_a);

	while (i <= 4)
	{
		key_nbr = get_key_nbr(stack_k, i); // Function to get the key number
		move_elements(stack, key_nbr); // Function to move numbers less than key number to stack B
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

t_node *copy_stack(t_node *head, t_stack *stack_k)
{
	t_node *new_head;
	t_node *current;
	
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
	int i;
	int key_nbr;
	t_node *current;

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
	while (next_nbr != 0)
	{
		move_nbr_to_top(stack, next_nbr);
		push_a_to_b(stack);
		next_nbr = find_next_nbr(stack->head_a, key_nbr);
	}
}





















// void optimal_move(t_stack *stack, int key_nbr)
// {
//     if (next_element_is_top(stack->head_a, key_nbr) && next_element_is_top(stack->head_b, key_nbr))
//     {
//         double_rotate(stack);
//     }
//     else if (next_element_is_bottom(stack->head_a, key_nbr) && next_element_is_bottom(stack->head_b, key_nbr))
//     {
//         double_reverse_rr(stack);
//     }
//     else if (needs_swap(stack->head_a) && needs_swap(stack->head_b))
//     {
//         double_swap(stack);
//     }
//     else
//     {
//         if (next_element_is_top(stack->head_a, key_nbr))
//         {
//             rotate(&stack->head_a, 'a', stack);
//         }
//         else if (next_element_is_bottom(stack->head_a, key_nbr))
//         {
//             reverse_rotate(&stack->head_a, 'a', stack);
//         }

//         if (next_element_is_top(stack->head_b, key_nbr))
//         {
//             rotate(&stack->head_b, 'b', stack);
//         }
//         else if (next_element_is_bottom(stack->head_b, key_nbr))
//         {
//             reverse_rotate(&stack->head_b, 'b', stack);
//         }
//     }
// }


// t_bool needs_swap(t_node *head)
// {
// 	if (head && head->next && head->value && head->next->value)
// 		return (is_true);
// 	return (is_false);
// }

// t_bool next_element_is_top(t_node *head, int key_nbr)
// {
// 	if (head && head->next && head->value && head->next->value == key_nbr)
// 		return (is_true);
// 	return (is_false);
// }

// t_bool next_element_is_bottom(t_node *head, int key_nbr)
// {
// 	t_node *current;

// 	current = head;
// 	while (current)
// 	{
// 		if (current && current->value == key_nbr)
// 			return (is_true);
// 		current = current->next;
// 	}
// 	return (is_false);
// }

