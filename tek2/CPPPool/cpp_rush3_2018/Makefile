##
## EPITECH PROJECT, 2022
## cpp_rush3_2018
## File description:
## Makefile
##

NAME	=	MyGKrellm

## Sources
SRC	=	src/main.cpp								\
		src/Parser/Parser.cpp						\
		src/MonitorCore/MonitorCore.cpp				\
		src/MonitorCore/Settings.cpp				\
		src/MonitorDisplay/IMonitorDisplay.cpp		\
		src/MonitorDisplay/Ncurse/MonitorNcurse.cpp	\
		src/MonitorDisplay/Sfml/MonitorSfml.cpp		\
		src/MonitorEvent/IMonitorEvent.cpp			\
		src/MonitorEvent/Ncurse/EventNcurse.cpp		\
		src/MonitorEvent/Sfml/EventSfml.cpp			\
		src/MonitorModule/IMonitorModule.cpp		\
		src/MonitorModule/InfoModule.cpp			\
		src/MonitorModule/CpuModule.cpp				\
		src/MonitorModule/MemoryModule.cpp			\
		src/MonitorModule/NetworkModule.cpp			\
		src/MonitorModule/DanModule.cpp				\
		src/MonitorModule/ReportsModule.cpp			\
		src/MonitorModule/BatteryModule.cpp			\
		src/MonitorDisplay/Sfml/Bar.cpp				\
		src/MonitorDisplay/Sfml/Text.cpp			\
		src/MonitorDisplay/Ncurse/Bar.cpp			\
		src/MonitorDisplay/Ncurse/Text.cpp			\
		src/MonitorDisplay/Ncurse/Container.cpp

OBJ	=	$(SRC:.cpp=.o)

## Compile
CC		=	g++
CFLAGS	=	-W -Wall -Wextra
LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lncurses

## Remove
RM	=	rm -f

## Colors
RED		=	\033[31;1m
GREEN	=	\033[32;1m
BLUE	=	\033[34;1m
NORMAL	=	\033[0m

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	echo -e "$(GREEN)[OK] $(NAME) compiled succesfully !$(NORMAL)"

%.o: %.cpp
	@echo -e "$(BLUE)[CC] $@ -> $<$(NORMAL)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make -C tests/ clean
	$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"

fclean:
	@make -C tests/ fclean
	@$(RM) $(OBJ) $(RM_FILE) && \
	echo -e "$(RED)[RM] $(NAME)'s object files$(NORMAL)"
	@$(RM) $(NAME) && echo -e "$(RED)[RM] $(NAME)$(NORMAL)"

re: fclean all

tests_run:
	@make -C tests/ tests_run

.PHONY: all clean fclean re tests_run
