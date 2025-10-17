#include "rbtree.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    rbtree *t = new_rbtree();

    printf("Tree->root: %u\n", t->root->color);
    printf("Tree->root: %u\n", t->nil->color);

    delete_rbtree(t);

    printf("Tree->root: %u\n", t->root->color);
    printf("Tree->root: %u\n", t->nil->color);
}
