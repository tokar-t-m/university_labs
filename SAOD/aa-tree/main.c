/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: AA-tree
 * Standard: C11
*/
#include <stdio.h>
#include "aa_tree.h"

int main(void)
{
    struct AANode *root;
    root = Initialize();

    root = Insert(10, root);
    root = Insert(85, root);
    root = Insert(15, root);
    root = Insert(70, root);
    root = Insert(20, root);
    root = Insert(60, root);
    root = Insert(30, root);

    //printf("%d\n", Find(10, root)->key);
    //printf("%d\n", Find(100, root)->key);
    //root = Remove(30, root);
    preOrder(root);
    printf("\n");
    delete_aatree(root);

    return 0;
}

