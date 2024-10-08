CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
LDFLAGS = -lssl -lcrypto

# Source files
SRC = main.c wallet.c transaction.c \
      ../blockchain/v0.2/block_create.c ../blockchain/v0.2/block_mine.c \
      ../blockchain/v0.2/blockchain_create.c ../blockchain/v0.2/block_destroy.c \
      ../crypto/hblk_crypto.c

OBJ = $(SRC:.c=.o)
EXEC = cli

# Build the CLI executable
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

# Clean up
clean:
	rm -f $(OBJ) $(EXEC)

rebuild: clean all
