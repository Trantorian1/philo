# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:08:48 by emcnab            #+#    #+#              #
#    Updated: 2023/04/11 14:20:00 by emcnab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                UNIX COLOR CODES                              #
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

# **************************************************************************** #
#                               COMPILATIONS VARS                              #
# **************************************************************************** #

DIR_BUILD = ./build
DIR_OBJS = $(DIR_BUILD)/objs
DIR_DEPS = $(DIR_BUILD)/deps
DIR_SRCS = ./src
DIR_INCL = ./include ./vendor/libft
DIR_BIN = ./bin

FILES_SRCS = $(shell find . -wholename "$(DIR_SRCS)/*.c")
FILES_OBJS = $(patsubst $(DIR_SRCS)/%.c,$(DIR_OBJS)/%.o,$(FILES_SRCS))
FILES_DEPS = $(patsubst $(DIR_SRCS)/%.c,$(DIR_DEPS)/%.d,$(FILES_SRCS))

C_COMPILER = clang
I_FLAGS = $(foreach dir,$(DIR_INCL),-I$(dir) )
C_FLAGS = -Wall -Wextra -Werror -Weverything -Wno-padded -g $(I_FLAGS)
C_DEPS = -MM -MP $(I_FLAGS)

BIN = $(DIR_BIN)/philo
LIB_FT = ./vendor/libft/libft.a
LIB_ARGS = -L$(dir $(LIB_FT)) -lft
LIB_GIT = $(dir $(LIB_FT))/.git

PROG = 0
TARGET = 1

# **************************************************************************** #
#                               COMPILATIONS TASKS                             #
# **************************************************************************** #

# @brief Default rule, calls dry run and compiles binary
all: dry_run $(BIN)



# @brief Builds main project binary.
#
# Builds project binary and displays compilation progress (100%). Will create
# binary directory if not already present. This rule will only be executed once
# the libf has been compiled, and all object and dependency files have been
# generated.
$(BIN): $(LIB_FT) $(FILES_OBJS) $(FILES_DEPS)
# 	displays build status
	@echo "$(BOLD)$(BLUE)building $(WHITE)$(BIN)$(RESET)"
	@printf "$(BOLD)$(WHITE)[100.00%%]$(RESET)"
# 	displays build command
	@printf " $(GREEN)$(C_COMPILER) $(C_FLAGS) $(FILES_OBJS) -o $(BIN) $(LIB_ARGS)$(RESET)\n"
# 	builds binary
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) $(FILES_OBJS) -o $(BIN) $(LIB_ARGS)



# @brief Builds object files.
#
# Builds object files, copying the structure of the src/ folder. Any missing
# directories will be created. 
# Also displays the current progress in the compilation. Progress is calculated
# based on the number of commands executed by Make, so this should be accurate
# even with Make dependency tracking.
#
# @warning Has not been tested in a multithread environment yet.
$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
# 	increments the number of files compiled
	@$(eval PROG=$(shell echo $$(($(PROG)+1))))
# 	displays build status. We have to do a bit of voodo shit by redirecting any
# 	error from bc since this seems to cause errors when running make -n in the
# 	dry_run task
	@printf "$(BOLD)$(WHITE)[%6.2f%%]$(RESET)" $(shell echo "scale=2;$(PROG)/($(TARGET)) * 100" | bc 2>/dev/null)
# 	displays build command
	@printf " $(GREEN)$(C_COMPILER) $(C_FLAGS) -c $< -o $@\n$(RESET)"
# 	builds object file
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) -c $< -o $@



# @brief Builds dependency files.
#
# Builds dependency files, copying the structure of the src/ folder. Any missing
# directories will be created.
#
# @warning Has not been tested in a multithread environment yet.
$(DIR_DEPS)/%.d: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) $(C_DEPS) -MT $(DIR_OBJS)/$*.o -MF $@ $<



# @brief Builds the libft
#
# This will only execute once the libft gitmodule has been initialised.
$(LIB_FT): $(LIB_GIT)
	@echo "$(BOLD)$(BLUE)building $(WHITE)$(LIB_FT)$(RESET)"
	@rake -s -C $(@D)



# @brief Initialises git submodules
$(LIB_GIT):
	@echo "initialising git submodules..."
	@git submodule init && git submodule update



# @brief Calculates the number of rules to be executed.
#
# This is used to accuratly determine the number of object files to be generated
# in order to calculate compilation status. Object file compilation is detected
# by grepping their progress.
dry_run:
# 	rules to be executed are stored in a file to be read. For some reason,
# 	running this directly as a shell command causes an infinite recursion...
	@make -n > $(DIR_BUILD)/dry_run.txt
#	greps the numbre of objec files to be generated
	@$(eval TARGET=$(shell cat $(DIR_BUILD)/dry_run.txt | grep %6.2f%% | wc -l))
#	counts the final binary as part of the compilation
	@$(eval TARGET=$(shell echo $$(($(TARGET)+1))))



# @brief Removes any object or dependency file that was generated
clean:
	@echo "$(RED)removing $(WHITE)*.o$(RESET)"
	@rm $(FILES_OBJS)
	@echo "$(RED)removing $(WHITE)*.d$(RESET)"
	@rm $(FILES_DEPS)



# @brief Removes any object or dependency file that was generated as well as the
# project binary
fclean: clean
	@echo "$(BOLD)$(RED)removing $(WHITE)$(BIN)$(RESET)"
	@rm $(BIN)



# @brief Removes any build artifacts and recompiles the project.
re: fclean
	@make -s all



# @brief displays debug info
debug:
	@echo $(FILES_SRCS)
	@echo $(FILES_OBJS)
	@echo $(FILES_DEPS)
	@echo $(C_FLAGS)
	echo $(TARGET)



# dependency inclusion
-include $(FILES_DEPS)



# all cannot be executed in parallel since we always need to generate dry_run
# before executing $(BIN)
.NOTPARALLEL: all
.PHONY: all submodules clean fclean re debug
