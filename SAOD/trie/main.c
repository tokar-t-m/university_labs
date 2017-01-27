#include <stdio.h>
#include "trie.h"

int main(void)
{
    struct trie *root;

    root = trie_insert(NULL, "bars", "60");
    root = trie_insert(root, "baribal", "100");
    root = trie_insert(root, "kit", "3000");
    root = trie_insert(root, "lev", "500");
    root = trie_insert(root, "bars", "70");

    trie_print(root, 0);

    printf("Lookup 'bars': %s\n", trie_lookup(root, "bars"));
    trie_print(root, 0);

    return 0;
}

