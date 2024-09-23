NAME    		:= libft
LIB     		:= libft.a
HEADER  		:= myLib.h ft_system.h ./optLib/optLib.h
SOURCE  		:= ft_atoi.c ft_memcpy.c ft_memset.c ft_putc.c ft_strcmp.c ft_strlen.c showBits.c strcat.c strsjoin.c ft_is.c ft_hexchartonum.c ft_memcmp.c ft_realloc.c ft_vector.c
OPT_SOURCE		:= $(wildcard optLib/*.c)
OBJ_DIR 		:= .obj_dir
OBJ     		:= $(addprefix $(OBJ_DIR)/,$(SOURCE:.c=.o))
OBJ 	 		+= $(addprefix $(OBJ_DIR)/,$(OPT_SOURCE:.c=.o))
RM      		:= rm -rf
CFLAGS  		:=
DEBFLAGS 		:= -g3

all: create_dir $(LIB)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile
	@printf "\033[1;32m$@\033[0m\n\033[1;34m"
	mkdir -p $(dir $@)
	@sleep 0.02
	${CC} ${CFLAGS} -c $< -o $@; 
	@printf "\033[0m"

$(LIB): $(OBJ) $(HEADER) Makefile
	@ar rc ${LIB} $(OBJ)

$(NAME): $(LIB)
	@$(CC) $(OBJ) -o $@

create_dir :
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir $(OBJ_DIR); \
	fi
	
clean:
	@if [ -d $(OBJ_DIR) ];\
	then \
		$(RM) $(OBJ_DIR); \
		printf "\033[1;32m$(NAME) deleted\n\033[0m"; \
	fi
	
fclean : clean
	@if [ -f $(LIB) ]; \
	then \
		$(RM) $(LIB); \
		printf "\033[1;32m$(LIB) deleted\n\033[0m"; \
	fi
	@if [ -f $(NAME) ]; \
	then \
		$(RM) $(NAME); \
		printf "\033[1;32m$(NAME) deleted\n\033[0m"; \
	fi

debug: DEBFLAGS += $(CFLAGS)
debug: all

	
re: fclean all

.PHONY: re all fclean clean
