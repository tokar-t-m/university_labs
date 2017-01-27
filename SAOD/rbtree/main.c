#include <stdio.h>
#include "rbtree.h"

int main(void)
{
    struct rbtree *tree = NULL, *node;
    tree = rbtree_add(tree, 10, "10");
    tree = rbtree_add(tree, 5, "5");
    tree = rbtree_add(tree, 3, "3");
    tree = rbtree_add(tree, 11, "11");
    tree = rbtree_add(tree, 12, "12");
    tree = rbtree_add(tree, 6, "6");
    tree = rbtree_add(tree, 8, "8");
    tree = rbtree_add(tree, 9, "9");
    printf("Исходное RBTree:\n");
    rbtree_print(tree, 0);

    node = rbtree_max(tree);
    printf("Max: %d\n", node->key);

    node = rbtree_min(tree);
    printf("Min: %d\n", node->key);

    node = rbtree_lookup(tree, 10);
    printf("Lookup: %s\n", node->value);

    printf("Исходное RBTree:\n");
    rbtree_delete(tree, 10);
    rbtree_print(tree, 0);

    rbtree_free(tree);

    return 0;
}
