#----------------------- Makefile for push_swap ---------------------------# 
################################ Colors ####################################    

RED      	= \033[1;31m
GREEN    	= \033[1;32m
YELLOW   	= \033[1;33m
BLUE     	= \033[1;34m
RESET    	= \033[0m

################################ Project ####################################

NAME 		= push_swap
# NAME_BONUS = checker
LIBFT 		= ./libft
PUSH_SWAP 	= ./
HEADER 		= ./mandatory/

################################ Sources ####################################

SUBDIRS 	= mandatory
MAND_SRCS 	= ./init/ps_add.c ./init/ps_checks.c ./init/ps_init.c ps_memory_free.c \
			./moves/ps_swap.c ./moves/ps_rotate.c ./moves/ps_push.c ./moves/ps_reverse_rotate.c \
			./moves/ps_utils.c ./sorting/ps_sort3.c ./sorting/ps_sort5.c  ./tests/test_radix.c \
			./sorting/ps_sort_short.c ./sorting/radix/ps_radix.c
			
# BONUS_SRCS 	= checker.c

SRCS 		= $(addprefix ./mandatory/, $(MAND_SRCS))
# BONUS_SRCS 	= $(BONUS_SRCS:%.c=bonus/%.c)

################################ Objects ####################################

OBJS 		= $(SRCS:.c=.o)
# BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)
OBJDIR 		= ./objs

################################# Compilate #################################

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_MAKE = $(MAKE) -C $(LIBFT) --no-print-directory
LIBFT_LIB = $(LIBFT)/libft.a

################################## Rules ####################################

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS:%=$(OBJDIR)/%)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS:%=$(OBJDIR)/%) -I $(HEADER) -L $(LIBFT) -lft
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(LIBFT_LIB):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@$(LIBFT_MAKE)
	@echo "$(GREEN)Libft compiled$(RESET)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

################################## Norm #####################################

norm:
	@echo "$(YELLOW)Norminette:$(RESET)"
	@norminette $(SRCS) $(HEADER)
	@echo "$(GREEN)Norminette done$(RESET)"

################################## Clean ####################################

clean:
	@$(LIBFT_MAKE) clean
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)Objects deleted$(RESET)"

fclean: clean
	@$(LIBFT_MAKE) fclean
	@rm -rf $(NAME)
	@echo "$(YELLOW)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re norm


