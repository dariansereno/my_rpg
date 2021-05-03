##
## EPITECH PROJECT, 2020
## my_rpg
## File description:
## makefile
##

CC				=	gcc
CFLAGS			=	-W -Wall -Wextra -Wno-deprecated-declarations
CPPFLAGS		=	-I./include -g3
LDFLAGS			=	-L./ -lmy -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

SRC				=	$(wildcard src/*.c && src/game/*.c && \
					src/game/inputs/*.c && src/game/paralax/*.c \
					src/map/*.c && src/map/planets/*.c && \
					src/map/planets/list/*.c && src/map/planets/generation/*.c \
					&& src/map/planets/interacting/*.c && \
					src/map/planets/animation/*.c && src/ui/*.c && \
					src/ui/game/*.c &&src/ui/trade/*.c && src/ui/planet/*.c \
					&& src/game/ennemies/*.c && src/game/ennemies/list/*.c \
					&& src/path_finding/*.c && src/messages/*.c && src/game/inventory/*.c \
					&& src/ui/planet_card/*.c && src/ui/generate_ui/*.c && \
					&& src/ui/trade_card/*.c && src/screen/end/*.c && src/screen/menu/*.c \
					&& src/screen/loading/*.c && src/screen/*.c && src/sounds/*.c \
					&& src/screen/settings/*.c \
					&& src/game/trade/*.c)

OBJ				=	$(SRC:.c=.o)

NAME			=	my_rpg

all				: $(NAME)

$(NAME)			: lib/my/libmy.a $(OBJ)
				@echo "\033[1;37mBinary Compilation...\033[0m"
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
				@echo "\033[1;34m[OK] \033[1;32mCompilated binary\033[0m\033[1;31m [$(NAME)]\033[0m"

lib/my/libmy.a	:
				@echo "\033[1;37mLib Compilation...\033[0m"
				@$(MAKE) -C lib/my all
				@echo "\033[1;34m[OK] \033[1;32mLib Compilated\033[0m"

clean			:
				$(RM) $(OBJ)
				$(RM) $(NAME)
				$(RM) src/*~
				$(RM) *~
				$(RM) /#*#/
				$(MAKE) -C lib/my $@

fclean			:	clean
				$(MAKE) -C lib/my $@

re				:	fclean all