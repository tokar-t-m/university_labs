#ifndef RBTREE_H
#define RBTREE_H
#include <stdlib.h>
#include <stdio.h>
#define COLOR_BLACK 1
#define COLOR_RED 0

struct rbtree{
    int key;
    char *value;
    int color;

    struct rbtree *parent;
    struct rbtree *left;
    struct rbtree *right;
}rbtree;

struct rbtree *rbtree_right_rotate(struct rbtree *root, struct rbtree *node);
struct rbtree *rbtree_left_rotate(struct rbtree *root, struct rbtree *node);
struct rbtree *rbtree_fixup_add(struct rbtree *root, struct rbtree *node);
struct rbtree *rbtree_add(struct rbtree *root, int key, char *value);
struct rbtree *rbtree_min(struct rbtree *root);
struct rbtree *rbtree_max(struct rbtree *root);
struct rbtree *rbtree_lookup(struct rbtree *root, int key);
void rbtree_free(struct rbtree *root);
void rbtree_print(struct rbtree *root, int level);
struct rbtree *rbtree_successor(struct rbtree *node);
void rbtree_fixup_delete(struct rbtree *root, struct rbtree *x);
void rbtree_delete(struct rbtree *root, int key);
#endif
