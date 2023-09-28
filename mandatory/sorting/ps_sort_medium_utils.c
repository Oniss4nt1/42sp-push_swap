/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_medium_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:27:45 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/28 18:09:11 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *merge(t_node *a, t_node *b);
void partition(t_node *head, t_node **front, t_node **back);

t_node	*merge_sort(t_node *head)
{
	t_node *a;
	t_node *b;
	
	if ((head == NULL) || (head->next == NULL))
		return head;

	partition(head, &a, &b);

	a = merge_sort(a);
	b = merge_sort(b);

	return merge(a, b);
}

t_node *merge(t_node *a, t_node *b)
{
	t_node *result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	
	if (a->value <= b->value)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return (result);
}

void partition(t_node *head, t_node **front, t_node **back)
{
	t_node *fast;
	t_node *slow;
	

	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
		
	}
}
