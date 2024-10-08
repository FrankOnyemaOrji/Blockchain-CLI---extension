#include <stdio.h>
#include <assert.h>
#include "../blockchain/v0.2/blockchain.h"

void test_blockchain_create(void)
{
    blockchain_t *blockchain = blockchain_create();

    assert(blockchain != NULL);
    assert(blockchain->chain != NULL);

    printf("Blockchain creation test passed!\n");
    blockchain_destroy(blockchain);
}

void test_block_create(void)
{
    blockchain_t *blockchain = blockchain_create();
    block_t *block = block_create(NULL, (int8_t *)"Genesis Block", 13);

    assert(block != NULL);
    assert(block->data.len == 13);

    printf("Block creation test passed!\n");
    block_destroy(block);
    blockchain_destroy(blockchain);
}

void test_block_hash(void)
{
    blockchain_t *blockchain = blockchain_create();
    block_t *block = block_create(NULL, (int8_t *)"Test Block", 10);

    uint8_t hash[SHA256_DIGEST_LENGTH];
    block_hash(block, hash);

    assert(hash != NULL);

    printf("Block hash test passed!\n");
    block_destroy(block);
    blockchain_destroy(blockchain);
}

int main(void)
{
    test_blockchain_create();
    test_block_create();
    test_block_hash();

    printf("All blockchain tests passed!\n");
    return 0;
}
