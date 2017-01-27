/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: AA-tree
 * Standard: C11
*/
#ifndef AA_TREE_H
#define AA_TREE_H
struct AANode{
    int key;
    struct AANode *left, *right;
    int level;
};
struct AANode *rightRotate(struct AANode *x);
struct AANode *leftRotate(struct AANode *x);
struct AANode *Skew(struct AANode *AA_tree);
struct AANode *Split( struct AANode *AA_tree );
struct AANode *Initialize( void );
struct AANode *new_aanode(int key);
struct AANode *Find( int key, struct AANode *AA_tree);
struct AANode *Insert( int key, struct AANode *AA_tree );
struct AANode *Remove(int key, struct AANode *AA_tree);
void preOrder(struct AANode *AA_tree);
void delete_aatree(struct AANode *AA_tree);
#endif // AA_TREE_H
