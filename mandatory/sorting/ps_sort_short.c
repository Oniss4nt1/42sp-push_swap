/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:04:26 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/27 14:22:19 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_short(t_stack *stack)
{


    if (stack->size_a == 2)
    {
        if (stack->head_a->value > stack->head_a->next->value)
            swap(&stack->head_a, 'a', stack);
        return ;
    }


    if (stack->size_a < 3 || stack->size_a > 10)
        return ;

    while (stack->size_a > 3)
    {
        move_min_top(stack);
        push_a_to_b(stack);
    }

    sort_three(&stack->head_a, stack->size_a, stack);

    while (stack->size_b > 0)
    {
        push_b_to_a(stack);
        if (stack->head_a->value > stack->head_a->next->value)
            swap(&stack->head_a, 'a', stack);
    }
}


// t_node *getTail(t_node *cur) {
//     while (cur != NULL && cur->next != NULL)
//         cur = cur->next;
//     return cur;
// }

// t_node *partition(t_node *head, t_node *end, t_node **newHead, t_node **newEnd) {
//     t_node *pivot = end;
//     t_node *prev = NULL, *cur = head, *tail = pivot;

//     while (cur != pivot) {
//         if (cur->value < pivot->value) {
//             if ((*newHead) == NULL)
//                 (*newHead) = cur;
//             prev = cur;  
//             cur = cur->next;
//         } else {
//             if (prev)
//                 prev->next = cur->next;
//             t_node *tmp = cur->next;
//             cur->next = NULL;
//             tail->next = cur;
//             tail = cur;
//             cur = tmp;
//         }
//     }

//     if ((*newHead) == NULL)
//         (*newHead) = pivot;

//     (*newEnd) = tail;

//     return pivot;
// }

// t_node *quickSortRecur(t_node *head, t_node *end) {
//     if (!head || head == end)
//         return head;

//     t_node *newHead = NULL, *newEnd = NULL;

//     t_node *pivot = partition(head, end, &newHead, &newEnd);

//     if (newHead != pivot) {
//         t_node *tmp = newHead;
//         while (tmp->next != pivot)
//             tmp = tmp->next;
//         tmp->next = NULL; 

//         newHead = quickSortRecur(newHead, tmp);

//         tmp = getTail(newHead);
//         tmp->next =  pivot;
//     }

//     pivot->next = quickSortRecur(pivot->next, newEnd);

//     return newHead;
// }

// void quickSort(t_node **headRef) {
//     (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
//     return;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // ... (Inclua aqui as definições de suas estruturas e funções de ordenação)

// void push(t_node** head_ref, int new_data) {
//     t_node* new_node = (t_node*) malloc(sizeof(t_node));
//     new_node->value  = new_data;
//     new_node->next = (*head_ref);
//     (*head_ref)    = new_node;
// }

// void printList(t_node *node) {
//     while (node != NULL) {
//         printf("%d ", node->value);
//         node = node->next;
//     }
//     printf("\n");
// }

// int main() {
//     t_node *a = NULL;
//     push(&a, -12);
//     push(&a, 99);
//     push(&a, 67);
//     push(&a, -200);
//     push(&a, -5);
//     push(&a, 0);
//     push(&a, 2);
//     push(&a, 1);

//     printf("Lista antes da ordenação: \n");
//     printList(a);

//     quickSort(&a);

//     printf("Lista após a ordenação: \n");
//     printList(a);

//     return 0;
// }
