# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:08:48 by emcnab            #+#    #+#              #
#    Updated: 2023/04/06 16:49:45 by emcnab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m
BLINK = \033[5m
REVERSE = \033[7m
HIDDEN = \033[8m

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

BLACK_BG = \033[40m
RED_BG = \033[41m
GREEN_BG = \033[42m
YELLOW_BG = \033[43m
BLUE_BG = \033[44m
MAGENTA_BG = \033[45m
CYAN_BG = \033[46m
WHITE_BG = \033[47m

DIR_BUILD = ./build
DIR_OBJS = $(DIR_BUILD)/objs
DIR_DEPS = $(DIR_BUILD)/deps
DIR_SRCS = ./src
DIR_INCL = ./include
DIR_BIN = ./bin

FILES_SRCS = $(shell find . -wholename "$(DIR_SRCS)/*.c")
FILES_OBJS = $(patsubst $(DIR_SRCS)/%.c,$(DIR_OBJS)/%.o,$(FILES_SRCS))
FILES_DEPS = $(patsubst $(DIR_SRCS)/%.c,$(DIR_DEPS)/%.d,$(FILES_SRCS))

C_COMPILER = clang
C_FLAGS = -Wall -Wextra -Werror -Weverything -I$(DIR_INCL)
C_DEPS = -MM -MP -I$(DIR_INCL)

BIN = $(DIR_BIN)/philo
LIB_FT = ./vendor/libft/libft.a
LIB_ARGS = -L$(dir $(LIB_FT)) -lft
LIB_GIT = $(dir $(LIB_FT))/.git

PROG = 0
TARGET = 1

all: dry_run $(BIN)

$(BIN): $(LIB_FT) $(FILES_OBJS) $(FILES_DEPS)
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) $(FILES_OBJS) -o $(BIN) $(LIB_ARGS)
	@echo "$(BOLD)$(BLUE)building $(WHITE)$(BIN)$(RESET)"
	@printf "$(BOLD)$(WHITE)[100.00%%]$(RESET)"
	@printf " $(GREEN)$(C_COMPILER) $(C_FLAGS) $(FILES_OBJS) -o $(BIN) $(LIB_ARGS)$(RESET)\n"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	@$(eval PROG=$(shell echo $$(($(PROG)+1))))
	@printf "$(BOLD)$(WHITE)[%6.2f%%]$(RESET)" $(shell echo "scale=2;$(PROG)/($(TARGET)) * 100" | bc 2>/dev/null)
	@printf " $(GREEN)$(C_COMPILER) $(C_FLAGS) -c $< -o $@\n$(RESET)"
	@$(C_COMPILER) $(C_FLAGS) -c $< -o $@

$(DIR_DEPS)/%.d: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) $(C_DEPS) -MT $(DIR_OBJS)/$*.o -MF $@ $<

$(LIB_FT): $(LIB_GIT)
	@make submodules
	@echo "building libft..."
	@rake -s -C $(@D)

$(LIB_GIT):
	@echo "initialising git submodules..."
	@git submodule init && git submodule update

dry_run:
	@make -n > $(DIR_BUILD)/dry_run.txt
	@$(eval TARGET=$(shell cat $(DIR_BUILD)/dry_run.txt | grep %6.2f%% | wc -l))
	@$(eval TARGET=$(shell echo $$(($(TARGET)+1))))

clean:
	@echo "$(RED)removing $(WHITE)*.o$(RESET)"
	@rm $(FILES_OBJS)
	@echo "$(RED)removing $(WHITE)*.d$(RESET)"
	@rm $(FILES_DEPS)

fclean: clean
	@echo "$(BOLD)$(RED)removing $(WHITE)$(BIN)$(RESET)"
	@rm $(BIN)

re: fclean
	@make -s all

debug:
	@echo $(FILES_SRCS)
	@echo $(FILES_OBJS)
	@echo $(FILES_DEPS)
	echo $(TARGET)

-include $(FILES_DEPS)

.PHONY: all submodules clean fclean re debug
.NOTPARALLEL: all
