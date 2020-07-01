# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 10:47:14 by smaccary          #+#    #+#              #
#    Updated: 2020/07/01 01:48:32 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mandelbrot.out

CC = clang

INCLUDE_PATH = ./includes/

INCLUDES = -I$(INCLUDE_PATH) -I$(INCLUDE_PATH)/structs

CFLAGS = -Wall -Wextra $(INCLUDES) -g3 -Ofast

RM = rm -rf

DIRSRC = ./src/

SRC = $(addprefix $(DIRSRC), \
			main.c events.c frontend.c init.c \
		)

OBJDIR = ./obj/

OBJ = $(SRC:.c=.o)

HEADERS = $(addprefix $(INCLUDE_PATH), \
			events.h init.h frontend.h mandelbrot.h \
			)

OBJBONUS = $(SRCBONUS:.c=.o)

LINKS = -lmlx

FRAMEWORKS = 

UNAME = $(shell uname)

ifeq ($(UNAME),Darwin)
	FRAMEWORKS += -framework OpenGL -framework Appkit
else
	LINKS += -lXext -lX11 -lxcb -lXau -lXdmcp -lm
endif

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L/usr/local/lib $(LINKS) $(FRAMEWORKS)


obj/%.o: $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRC) -o $@


clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME) 

lilclean:
	$(RM) $(OBJ) $(OBJBONUS)
	$(RM) $(NAME) 

re: fclean all	

.PHONY: clean fclean

debug:
	$(eval CFLAGS += -fsanitize=address)

QWERTY:
	$(eval CFLAGS += -D QWERTY=1)
