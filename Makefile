SERVER = server

CLIENT = client

SRCS = server.c server_utils.c ft_printf.c ft_putchar.c ft_putnbr.c 

SRCSBIS = client.c client_utils.c

OBJECT = $(SRCS:.c=.o)

OBJECTBIS = $(SRCSBIS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJECTBIS)

		$(CC) -o $(CLIENT) $(OBJECTBIS) 

$(SERVER): $(OBJECT)

		$(CC) -o $(SERVER) $(OBJECT) 
	
.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		rm -f $(OBJECT) $(OBJECTBIS)

fclean: clean
		rm -f $(SERVER) $(CLIENT)

re: 	fclean $(SERVER) $(CLIENT)

.PHONY: all clean fclean re bonus 