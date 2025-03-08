server = server
client = client
NAME = $(server) $(client)
CC = cc
CFLAGS = -Wall -Wextra -Werror

serversrc = server.c utils.c
clientsrc = client.c utils.c

server_OBJ = $(serversrc:.c=.o)
client_OBJ = $(clientsrc:.c=.o)
OBJ = $(server_OBJ) $(client_OBJ)

all: $(NAME)

$(server): $(server_OBJ)
	$(CC) $(CFLAGS) $(server_OBJ) -o $(server)

$(client): $(client_OBJ)
	$(CC) $(CFLAGS) $(client_OBJ) -o $(client)

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all