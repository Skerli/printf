NAME    =   libftprintf.a
LIST    =   ft_printf.c main2.c main3.c 
LIST_B  =
OBJ =   $(patsubst %.c,%.o,$(LIST))
OBJ_B   =   $(patsubst %.c,%.o,$(LIST_B))
D_FILES =   $(patsubst %.c,%.d,$(LIST) $(LIST_B))
OPTFLAGS    =   -o2
FLAGS   =   -Wall -Wextra -Werror
all :   $(NAME)
$(NAME) :   $(OBJ)
	ar rcs $(NAME) $?
%.o :   %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD
include $(wildcard $(D_FILES))
bonus   :
	@make OBJ="$(OBJ_B)" all
clean   :
	@rm -f $(OBJ) $(OBJ_B) $(D_FILES)
fclean  :   clean
	@rm -f $(NAME)
re  :   fclean all
.PHONY  :   all clean fclean re bonus