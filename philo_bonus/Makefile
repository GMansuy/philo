
# VARIABLES

NAME		= 
NAME_BONUS	= $(addsuffix $(NAME, ))

LIB_DIR		= libft
LIB			= libft/libft.a

SRC_DIR		= src/
OBJ_DIR		= obj/
BONUS_DIR	= src_bonus/

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -I./include -MMD -MP

RM			= rm -rf
AR			= ar rcs
SAN			= -fsanitize=address

# SOURCES

# SUB_DIR = 
# SUB_FILES = 

# ALL_DIRS	+=	$(OBJ_DIR)
# ALL_DIRS	+=	$(addprefix $(OBJ_DIR), $(MAIN_DIR))

SRC_FILES	+= $(addprefix $(MAIN_DIR), $(MAIN))
SRC_FILES	+= $(addprefix $(PIPE_DIR), $(PIPE))

C_FILES		=	$(addsuffix .c, $(SRC_FILES))
SRCS 		=	$(addprefix $(SRC_DIR), $(C_FILES))
OBJS 		=	$(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
DEPS		=	$(OBJS:.o=.d)

# BONUS

SUBDIR_BONUS =
SUBFILES_BONUS =

SRC_FILES_BONUS	+= 	$(addprefix $(SUBDIR_BONUS), $(SUBFILES_BONUS))
SRC_FILES_BONUS	+= $(SRC_FILES)

C_FILES_BONUS	=	$(addsuffix _bonus.c, $(SRC_FILES_BONUS))
SRCS_BONUS 		=	$(addprefix $(BONUS_DIR), $(C_FILES_BONUS))
OBJS_BONUS 		=	$(addprefix $(OBJ_DIR), $(C_FILES_BONUS:.c=.o))
DEPS_BONUS		=	$(OBJS_BONUS:.o=.d)


# 	MANDATORY
all: 		$(LIB) obj $(NAME)
			

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@ $(LIB)
			@echo "$(RED)$(NAME) compiled !$(CYAN)"

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c 
			$(CC) $(CFLAGS) -c -o $@ $< 
			@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

#	BONUS
bonus:		$(LIB) obj $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
			@$(CC) $(CFLAGS) $^ -o $(NAME_BONUS) $(LIB)
			@echo "$(RED)$(NAME_BONUS) BONUS compiled !$(CYAN)"

$(OBJ_DIR)%.o: 	$(BONUS_DIR)%.c 
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c -o $@ $< 
			@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

$(LIB):
			@echo "$(MAGENTA)Creating libft files...$(CYAN)"
			@make -s -C ./libft

# 	RULES
obj:
			@mkdir -p $(ALL_DIRS)

clean:
			@make clean -C $(LIB_DIR)
			@$(RM) $(OBJ_DIR) $(DEPS_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME_BONUS)
			@$(RM) -f $(LIB_DIR)/libft.a

re:			fclean
			@make all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

.PHONY: all clean fclean re	

.SILENT: lib

-include $(DEPS)

# COLORS

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
