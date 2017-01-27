#include "rbtree.h"

struct rbtree EmptyNode = {0, 0, COLOR_BLACK, NULL, NULL, NULL}; //???
struct rbtree *NullNode = &EmptyNode; //???

struct rbtree *rbtree_right_rotate(struct rbtree *root, struct rbtree *node){
    struct rbtree *left = node->left;
    /*Create node->left link*/
    node->left = left->right;
    if(left->right != NullNode)
        left->right->parent = node;
    /*Create left->parent link*/
    if(left != NullNode)
        left->parent = node->parent;
    if(node->parent != NullNode){
        if(node == node->parent->right)
            node->parent->right = left;
        else
            node->parent->left = left;
    }else{
        root = left;
    }
    left->right = node;
    if(node != NullNode)
        node->parent = left;
    return root;
}

struct rbtree *rbtree_left_rotate(struct rbtree *root, struct rbtree *node){
    struct rbtree *right = node->right;
    /*create node ->right link*/
    node->right = right->left;
    if(right->left != NullNode)
        right->left->parent = node;
    /*Create right->parent link*/
    if(right != NullNode)
        right->parent = node->parent;
    if(node->parent != NullNode){
        if(node == node->parent->left)
            node->parent->left = right;
        else
            node->parent->right = right;
    }else{
        root = right;
    }
    right->left = node;
    if(node != NullNode)
        node->parent = right;
    return root;
}

struct rbtree *rbtree_fixup_add(struct rbtree *root, struct rbtree *node){
    struct rbtree *uncle;
    /*Current node is RED*/
    while(node != root && node->parent->color == COLOR_RED){
        if(node->parent == node->parent->parent->left){
            /*Node in left tree of grandfather*/
            uncle = node->parent->parent->right;
            if(uncle->color == COLOR_RED){
                /*Case 1 - uncle is RED*/
                node->parent->color = COLOR_BLACK;
                uncle->color = COLOR_BLACK;
                node->parent->parent->color = COLOR_RED;
                node = node->parent->parent;
            }else{
                /*Cases 2 & 3 - uncle is BLACK*/
                if(node == node->parent->right){
                    /*Reduce case 3 to case 3*/
                    node = node->parent;
                    root = rbtree_left_rotate(root, node);
                }
                /*Case 3*/
                node->parent->color = COLOR_BLACK;
                node->parent->parent->color = COLOR_RED;
                root = rbtree_right_rotate(root, node->parent->parent);
            }
        }else{
            /*
            * Node in right tree of grandfather
            * Cases 4, 5, 6 - node in right tree of grandfather
            */
            uncle = node->parent->parent->left;
            if(uncle->color == COLOR_RED){
                /*Uncle is RED - case 4*/
                node->parent->color = COLOR_BLACK;
                uncle->color = COLOR_BLACK;
                node->parent->parent->color = COLOR_RED;
                node = node->parent->parent;
            }else{
                /*Uncle is BLACK*/
                if(node == node->parent->left){
                    node = node->parent;
                    root = rbtree_right_rotate(root, node);
                }
                node->parent->color = COLOR_BLACK;
                node->parent->parent->color = COLOR_RED;
                root = rbtree_left_rotate(root, node->parent->parent);
            }
        }
    }
    root->color = COLOR_BLACK;
    return root;
}

struct rbtree *rbtree_add(struct rbtree *root, int key, char *value){
    struct rbtree *node, *parent = NullNode;
    /*Search leaf for new element*/
    for(node = root; node != NullNode && node != NULL; ){
        parent = node;
        if(key < node->key)
            node = node->left;
        else if(key > node->key)
            node = node->right;
        else
            return root;
    }
    node = malloc(sizeof(*node));
    if(node == NULL)
        return NULL;
    node->key = key;
    node->value = value;
    node->color = COLOR_RED;
    node->parent = parent;
    node->left = NullNode;
    node->right = NullNode;
    if(parent != NullNode){
        if(key < parent->key)
            parent->left = node;
        else
            parent->right = node;
    }else{
        root = node;
    }
    return rbtree_fixup_add(root, node);
}

struct rbtree *rbtree_min(struct rbtree *root){

    if(root == NullNode){
        return NULL;
    }

    while(root -> left != NullNode){
        root = root -> left;
    }
    return root;
}

struct rbtree *rbtree_max(struct rbtree *root){

    if(root == NullNode){
        return NULL;
    }

    while(root -> right != NullNode){
        root = root -> right;
    }
    return root;
}

struct rbtree *rbtree_lookup(struct rbtree *root, int key){

    if (root == NullNode)
        return NULL;

    while(root != NullNode){
        if(key == root -> key){
            return root;
        } else {
            if(key < root -> key){
                root = root -> left;
            } else {
                root = root -> right;
            }
        }
    }
    return root;
}

void rbtree_free(struct rbtree *root){
    if (root == NullNode)
        exit(0);
    rbtree_free(root->left);
    rbtree_free(root->right);
    free(root);
}

void rbtree_print(struct rbtree *root, int level){
    int i;
    if (root == NullNode){
        return;
    }
    for (i = 0; i < level; i++){
        printf(" ");
    }
    printf("%d(%d)\n",root->key, root->color);
    rbtree_print(root->left, level++);
    rbtree_print(root->right, level++);
}

struct rbtree *rbtree_successor(struct rbtree *node){
    if (node->right != NullNode)
        return rbtree_min(node->right);

    struct rbtree *parent = node->parent;

    if (parent != NullNode && node == parent->right) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void rbtree_fixup_delete(struct rbtree *root, struct rbtree *x){
    /* x - node, w - brother */
    struct rbtree *w;

    while (x != root && x->color == COLOR_BLACK) {
        if(x == x->parent->left) {
            w = x->parent->right;
            if (w->color == COLOR_RED) {
                w->color = COLOR_BLACK;
                x->parent->color = COLOR_RED;
                root = rbtree_left_rotate(root, x->parent);
                w = x->parent->right;
            }

            if (w->left->color == COLOR_BLACK && w->right->color == COLOR_BLACK) {
                    w->color = COLOR_RED;
                    x = x->parent;
            } else {
                if (w->right->color == COLOR_BLACK) {
                    w->left->color = COLOR_BLACK;
                    w->color = COLOR_RED;
                    root = rbtree_right_rotate(root, w);
                    w = x->parent->right;
                }

                w->color = x->parent->color;
                x->parent->color = COLOR_BLACK;
                w->right->color = COLOR_BLACK;
                root = rbtree_left_rotate(root, x->parent);
                x = root;
            }
        } else {
            w = x->parent->left;
            if (w->color == COLOR_RED) {
                w->color = COLOR_BLACK;
                x->parent->color = COLOR_RED;
                root = rbtree_right_rotate(root, x->parent);
                w = x->parent->left;
            }

            if (w->right->color == COLOR_BLACK && w->left->color == COLOR_BLACK) {
                    w->color = COLOR_RED;
                    x = x->parent;
            } else {
                if (w->left->color == COLOR_BLACK) {
                    w->right->color = COLOR_BLACK;
                    w->color = COLOR_RED;
                    root = rbtree_left_rotate(root, w);
                    w = x->parent->left;
                }

                w->color = x->parent->color;
                x->parent->color = COLOR_BLACK;
                w->left->color = COLOR_BLACK;

                root = rbtree_right_rotate(root, x->parent);
                x = root;
            }
        }
    }
    x->color = COLOR_BLACK;
}

void rbtree_delete(struct rbtree *root, int key){
    struct rbtree *z = rbtree_lookup(root, key), *y, *x;
    /* y - delete, x - child, z - node*/

    if (!z || z == NullNode)
        return;

    if (z->left == NullNode || z->right == NullNode)
        y = z;
    else
        y = rbtree_successor(z);

    if (y->left != NullNode)
        x = y->left;
    else
        x = y->right;

    x->parent = y->parent;

    if (y->parent != NullNode)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    else
        root = x;


    if (y != z)
        z->key = y->key;

    if (y->color == COLOR_BLACK)
        rbtree_fixup_delete(root, x);

    free(y);
    printf("\ndeleted node complete\n");
}
