NAME    =   libftprintf.a
LIST    =   ft_printf.c fcd.c fxX.c fp.c ft_pr_plus.c fus.c
LIST_B  =
OBJ =   $(patsubst %.c,%.o,$(LIST))
OBJ_B   =   $(patsubst %.c,%.o,$(LIST_B))
D_FILES =   $(patsubst %.c,%.d,$(LIST) $(LIST_B))
OPTFLAGS    =   -o2
FLAGS   =   
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