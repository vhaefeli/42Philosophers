# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhaefeli <vhaefeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:28:53 by vhaefeli          #+#    #+#              #
#    Updated: 2022/08/26 11:21:39 by vhaefeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS 			= -Wall -Wextra -Werror -g #-fsanitize=address -fno-omit-frame-pointer
TARGET 			= philo
SRCS_DIR 		= ./src
OBJS_DIR 		= ./obj
LIBS			= -pthread
_SRCS 			= philo.c\


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
	$(CC) -c $(CFLAGS) -o $@ $^

$(TARGET): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

bonus: $(TARGET)



