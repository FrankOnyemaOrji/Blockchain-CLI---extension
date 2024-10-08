#include "../crypto/hblk_crypto.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new wallet (generates public/private keys)
int create_wallet(void)
{
    EC_KEY *key_pair = ec_create();
    if (!key_pair)
    {
        fprintf(stderr, "Error creating key pair\n");
        return 1;
    }

    if (!ec_save(key_pair, "wallet.pem"))
    {
        fprintf(stderr, "Error saving wallet to file\n");
        EC_KEY_free(key_pair);
        return 1;
    }

    printf("Wallet created and saved to 'wallet.pem'\n");
    EC_KEY_free(key_pair);
    return 0;
}

// Load and print wallet details
int load_wallet(const char *wallet_path)
{
    EC_KEY *key_pair = ec_load(wallet_path);
    if (!key_pair)
    {
        fprintf(stderr, "Error loading wallet\n");
        return 1;
    }

    printf("Wallet loaded successfully!\n");
    EC_KEY_free(key_pair);
    return 0;
}
