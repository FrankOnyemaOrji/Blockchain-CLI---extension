CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CFLAGS += -I../blockchain/v0.3 -I../crypto

# Ensure targets directory exists
TARGET_DIR = targets
$(shell mkdir -p $(TARGET_DIR))

OBJ = $(TARGET_DIR)/blockchain.o $(TARGET_DIR)/hblk_crypto.o
TEST_OBJ = $(TARGET_DIR)/test_wallet.o

all: tests

tests: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o tests $(OBJ) $(TEST_OBJ) -lssl -lcrypto

# Compile blockchain.c into targets directory
$(TARGET_DIR)/blockchain_create.o: ../blockchain/v0.3/blockchain.c
	$(CC) $(CFLAGS) -c ../blockchain/v0.3/blockchain.c -o $@

# Compile hblk_crypto.c into targets directory
$(TARGET_DIR)/hblk_crypto.o: ../crypto/hblk_crypto.c
	$(CC) $(CFLAGS) -c ../crypto/hblk_crypto.c -o $@

# Compile test_wallet.c into targets directory
$(TARGET_DIR)/test_wallet.o: test_wallet.c
	$(CC) $(CFLAGS) -c test_wallet.c -o $@

clean:
	rm -f $(TARGET_DIR)/*.o tests
