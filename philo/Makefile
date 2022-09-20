# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:28:53 by vhaefeli          #+#    #+#              #
#    Updated: 2022/09/20 21:15:10 by vhaefeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror -g #-fsanitize=address -fno-omit-frame-pointer
TARGET 			= philo
SRCS_DIR 		= ./src
OBJS_DIR 		= ./obj
INCLUDES_DIRS	= ./includes
INCLUDES		= $(addprefix -I,$(INCLUDES_DIRS))
LIBS			= -pthread
_SRCS 			= philo.c\
					ft_time.c\
					eat_sleep_live.c\
					ft_atoui_check.c\
					philo_utils.c\
					philo_check.c

OBJS 			= $(patsubst %.c, $(OBJS_DIR)/%.o, $(_SRCS))
SRCS 			= $(patsubst %, $(SRCS_DIR)/%, $(_SRCS))

.PHONY : all clean fclean re bonus test

all: $(TARGET)

clean:
	rm -f $(OBJS)
	rm -d $(OBJS_DIR)


fclean: clean
	rm -f $(TARGET)

re: fclean all

$(OBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) -c $(CFLAGS) -o $@ $^ $(INCLUDES)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES) $(LIBS)



