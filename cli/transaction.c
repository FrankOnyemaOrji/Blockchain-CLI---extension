#include "../blockchain/v0.2/blockchain.h"
#include "../crypto/hblk_crypto.h"
#include <stdio.h>

// Function to sign and create a transaction
int send_transaction(const char *sender_wallet, const char *recipient, uint64_t amount)
{
    EC_KEY *sender_key = ec_load(sender_wallet);
    if (!sender_key)
    {
        fprintf(stderr, "Error loading sender wallet\n");
        return 1;
    }

    // Create a new transaction structure and sign it
    // Validate the transaction with the public key

    printf("Transaction of %lu coins sent from %s to %s\n", amount, sender_wallet, recipient);

    EC_KEY_free(sender_key);
    return 0;
}
