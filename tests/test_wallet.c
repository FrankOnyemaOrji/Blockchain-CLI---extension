#include <stdio.h>
#include <assert.h>
#include <openssl/opensslv.h>
#include "../crypto/hblk_crypto.h"

void test_wallet_creation(void)
{
    EC_KEY *key = ec_create();
    assert(key != NULL);

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    printf("Wallet creation test passed!\n");
    EC_KEY_free(key);
}

void test_wallet_save_and_load(void)
{
    EC_KEY *key = ec_create();
    assert(key != NULL);

    int save_result = ec_save(key, "test_wallet.pem");
    assert(save_result == 1);

    EC_KEY *loaded_key = ec_load("test_wallet.pem");
    assert(loaded_key != NULL);

    printf("Wallet save and load test passed!\n");

#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    EC_KEY_free(key);
    EC_KEY_free(loaded_key);
}

int main(void)
{
    test_wallet_creation();
    test_wallet_save_and_load();

    printf("All wallet tests passed!\n");
    return 0;
}
