#include <stdio.h>
#include <string.h>
#include "../blockchain/v0.2/blockchain.h"
#include "../crypto/hblk_crypto.h"

void print_usage(void)
{
    printf("Usage: ./cli <command>\n");
    printf("Commands:\n");
    printf("  create-wallet       - Create a new wallet\n");
    printf("  check-balance       - Check wallet balance\n");
    printf("  send-transaction    - Send a transaction\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "create-wallet") == 0)
    {
        printf("Creating a new wallet...\n");
        // Call wallet creation function
    }
    else if (strcmp(argv[1], "check-balance") == 0)
    {
        printf("Checking wallet balance...\n");
        // Call function to check balance
    }
    else if (strcmp(argv[1], "send-transaction") == 0)
    {
        printf("Sending transaction...\n");
        // Call function to send transaction
    }
    else
    {
        print_usage();
        return 1;
    }

    return 0;
}
