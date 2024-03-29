# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/11 17:07:00 by sbos          #+#    #+#                  #
#    Updated: 2023/04/11 17:07:00 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := iter

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

################################################################################

ifdef O3
CFLAGS += -Ofast
endif
ifdef DEBUG
CFLAGS += -g3
CFLAGS += -Wfatal-errors
CFLAGS += -Wno-self-assign-overloaded
CFLAGS += --coverage -O0
endif
ifdef SAN
CFLAGS += -fsanitize=address
endif

################################################################################

CFILES := $(wildcard *.cpp **/*.cpp)

################################################################################

OBJDIR := obj
OBJFILES := $(addprefix $(OBJDIR)/,$(CFILES:cpp=o))

################################################################################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJFILES)
	@$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)
	@echo Created executable \'$(NAME)\'

################################################################################

.PHONY: clean
clean:
	@$(RM) -rf $(OBJDIR)
	@echo Deleted \'obj/\'

.PHONY: fclean
fclean: clean
	@$(RM) -f $(NAME)
	@echo Deleted executable \'$(NAME)\'

.PHONY: re
re: fclean all

.PHONY: coverage
coverage: re
	./$(NAME); cd obj; /Users/sbos/Library/Python/3.9/bin/gcovr --html-nested coverage.html -r ..

################################################################################

# Source and explanation: https://stackoverflow.com/a/52036564/13279557

DEPENDS := $(patsubst %.o,%.d,$(OBJFILES))

-include $(DEPENDS)

$(OBJDIR)/%.o : %.cpp Makefile
	@mkdir -p $(@D)
	@$(call tidy_compilation,$(CC) $(CFLAGS) -MMD -MP -c $< -o $@)

define tidy_compilation
	@printf "%s\e[K\n" "$(1)"
	@$(1)
	@printf "\e[A\e[K"
endef

################################################################################
