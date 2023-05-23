SERVER = server
CLIENT = client

CC = cc
RM = rm -rf 

CFILES_SERVER = server.c utils.c
OBJ_SERVER = $(CFILES_SERVER:%.c=%.o)

CFILES_CLIENT = client.c utils.c
OBJ_CLIENT = $(CFILES_CLIENT:%.c=%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) utils.c client.c -o $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) utils.c server.c -o $(SERVER)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all
