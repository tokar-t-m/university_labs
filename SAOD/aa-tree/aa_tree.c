/*
 * Author: Tokar T. M.
 * E - mail: tokar.t.m@gmail.com
 * Title: AA-tree
 * Standard: C11
*/
#include <stdio.h>
#include <malloc.h>
#include "aa_tree.h"

struct AANode *NullNode = NULL;
struct AANode *DeletePtr, *LastPtr;

struct AANode *rightRotate(struct AANode *x){
    struct AANode *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct AANode *leftRotate(struct AANode *x){
    struct AANode *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct AANode *Skew(struct AANode *AA_tree){
    if( AA_tree->left->level == AA_tree->level )
        AA_tree = rightRotate( AA_tree );
    return AA_tree;
}

struct AANode *Split( struct AANode *AA_tree ){
    if( AA_tree->right->right->level == AA_tree->level ) {
        AA_tree = leftRotate( AA_tree );
        AA_tree->level++;
    }
    return AA_tree;
}

struct AANode *Initialize(void){
    if( NullNode == NULL ) {
        NullNode = malloc( sizeof( struct AANode ) );
        if( NullNode == NULL )
           printf( "Out of space!!!" );
        NullNode->left = NullNode->right = NullNode;
        NullNode->level = 0;
    }
    return NullNode;
}

struct AANode *new_aanode(int key){
    struct AANode *AA_node = (struct AANode *)malloc(sizeof(struct AANode));
    if(AA_node == NULL) return NULL;
    AA_node->key = key;
    AA_node->level = 1;
    AA_node->left = AA_node->right = NullNode;
    return AA_node;
}

struct AANode *Find( int key, struct AANode *AA_tree){
    if( AA_tree == NullNode )
        return NullNode;
    if( key < AA_tree->key )
        return Find( key, AA_tree->left );
    else if( key > AA_tree->key )
        return Find( key, AA_tree->right );
    else
        return AA_tree;
}

struct AANode *Insert( int key, struct AANode *AA_tree ){
    if( AA_tree == NullNode ) {
        AA_tree = new_aanode(key);
        return AA_tree;
    }
    if( key < AA_tree->key )
        AA_tree->left = Insert( key, AA_tree->left );
    else if( key > AA_tree->key )
        AA_tree->right = Insert( key, AA_tree->right );
    else return AA_tree;

    AA_tree = Skew( AA_tree );
    AA_tree = Split( AA_tree );
    return AA_tree;
}

struct AANode *Remove(int key, struct AANode *AA_tree){
    if( AA_tree == NullNode ) return AA_tree;
    /* Step 1: Search down tree */
    /*         set LastPtr and DeletePtr */
    LastPtr = AA_tree;
    if( key < AA_tree->key )
        AA_tree->left = Remove(key, AA_tree->left);
    else {
        DeletePtr = AA_tree;
        AA_tree->right = Remove(key, AA_tree->right);
    }

    /* Step 2: If at the bottom of the tree and */
    /*         item is present, we remove it */
    /* Step 3: Otherwise, we are not at the bottom; */
    /*         rebalance */
    if( AA_tree == LastPtr && DeletePtr != NullNode && key == DeletePtr->key) {
            DeletePtr->key = AA_tree->key;
            DeletePtr = NullNode;
            AA_tree = AA_tree->right;
            free( LastPtr );
    } else if(AA_tree->left->level < AA_tree->level - 1
            || AA_tree->right->level < AA_tree->level - 1)
    {
        AA_tree->level--;
        if(AA_tree->right->level > AA_tree->level)
            AA_tree->right->level = AA_tree->level;
        AA_tree = Skew( AA_tree );
        AA_tree->right = Skew( AA_tree->right );
        AA_tree->right->right = Skew( AA_tree->right->right );
        AA_tree = Split( AA_tree );
        AA_tree->right = Split( AA_tree->right );
    }

    return AA_tree;
}

void delete_aatree(struct AANode *AA_tree) {
   if(AA_tree == NullNode) return;
   if(AA_tree->left != NullNode) delete_aatree(AA_tree->left);
   if(AA_tree->right != NullNode) delete_aatree(AA_tree->right);
   free(AA_tree);
}

void preOrder(struct AANode *AA_tree){
    if (AA_tree != NullNode)
    {
        printf("%d ", AA_tree->key);
        preOrder(AA_tree->left);
        preOrder(AA_tree->right);
    }
}

