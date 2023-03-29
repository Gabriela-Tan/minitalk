# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtan <gabtan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 13:44:40 by gabtan            #+#    #+#              #
#    Updated: 2023/03/24 13:44:44 by gabtan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
SSRC =	server.c
CLIENT = client
CSRC =	client.c
FOLDER = libft
LIB = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIB) $(SERVER) $(CLIENT)
	@echo "Server and client are good to go!"

$(LIB):
	@make -s -C $(FOLDER)

$(SERVER):
	$(CC) $(CFLAGS) $(SSRC) libft/libft.a -o $(SERVER)
	
$(CLIENT):
	$(CC) $(CFLAGS) $(CSRC) libft/libft.a -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -s -c $< -o $@

clean:
	rm $(SERVER) $(CLIENT)
	@make clean -s -C $(FOLDER)
	@echo "Cleaning successful"

fclean: clean
	@make fclean -s -C $(FOLDER)
	@echo "All generated files are deleted"
	
re: fclean all
	@echo "Remake completed"

.PHONY: all clean fclean re

