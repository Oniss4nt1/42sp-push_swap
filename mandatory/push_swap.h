/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:04:15 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 16:20:17 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>

//############################# Macros #########################################

# define INT_MIN -2147483648
# define INT_MAX 2147483647

//############################# Structures #####################################

typedef enum e_bool
{
	is_false,
	is_true
}					t_bool;

typedef struct s_numbers
{
	long int		*num;
	int				size;
}					t_numbers;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size_a;
	int				size_b;
	int				min_a;
	int				min_b;
	int				max_a;
	int				max_b;
	int				moves;
	t_node			*head_a;
	t_node			*head_b;
}					t_stack;

//############################# Prototypes #####################################
//############################# INIT ###########################################

t_stack				*init_stack(void);
t_node				*init_node(int value);
void				add_to_list(t_node **head, t_stack *stack, int value);
void				add_to_head(t_node **head, int value);

//############################# CHECK ##########################################

t_bool				is_integer(char *str);
t_bool				is_duplicate(t_node *head);
t_numbers			split_and_convert(char *str);
t_bool				check_value(int num);
t_bool				process_arguments(t_stack *stack, int argc, char **argv);
t_bool				is_sorted(t_node *head);

//############################# MEM FREE #######################################

void				free_list(t_node *head);
void				free_stack(t_stack *stack);

//############################# OPERATIONS #####################################

void				swap(t_node **head, char move, t_stack *stack);
void				double_swap(t_stack *stack);
void				rotate(t_node **head, char move, t_stack *stack);
void				double_rotate(t_stack *stack);
void				push_a_to_b(t_stack *stack);
void				push_b_to_a(t_stack *stack);
void				reverse_rotate(t_node **head, char move, t_stack *stack);
void				double_reverse_rr(t_stack *stack);

//############################# SORT ###########################################

void				sort_three(t_node **head, int size, t_stack *stack);
void				sort_five(t_stack *stack);
void				sort_short(t_stack *stack);
void				sort_medium(t_stack *stack);

//############################# UTILS ##########################################

int					find_min(t_node *head);
void				move_min_top(t_stack *stack);
int					find_distance_top(t_node *head, int min);

t_node				*merge_sort(t_node *head);
t_node				*merge(t_node *a, t_node *b);
void				partition(t_node *head, t_node **front, t_node **back);

t_node				*copy_stack(t_node *head, t_stack *stack_k);
int					get_key_nbr(t_stack *stack_k, int key);
void				move_elements(t_stack *stack, int key_nbr);

int					find_next_nbr(t_node *head, int key_nbr);
void				move_nbr_to_top(t_stack *stack, int nbr);

void				normalize_sort(t_stack *stack);
void				radix_sort(t_stack *stack);
void				radix_sort_stack_b(t_stack *stack, int i);

void				radix_sort(t_stack *stack);
int					get_max_bits(t_node *head);

//############################# DEBUG ##########################################

void				print_stacks(t_stack *stack);
void				print_list(t_node *head);

#endif