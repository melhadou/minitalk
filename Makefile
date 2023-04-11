SERVER = server
CLIENT = client

CC = cc
RM = rm -rf 
CFILES = server.c utils.c client.c
OBJ = $(CFILES:%.c=%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ)
	$(CC) utils.c client.c -o $(CLIENT)

$(SERVER): $(OBJ)
	$(CC) utils.c server.c -o $(SERVER)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
re: fclean all
