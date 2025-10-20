#include "rbtree.h"
#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  node_t *nil = (node_t *)calloc(1, sizeof(node_t));
  nil->color = RBTREE_BLACK;
  p->nil = nil;
  p->root = nil;
  return p;
}

void nodeTreeDelete(rbtree *t, node_t *cur) {
  if (cur == t->nil) { return; }
  nodeTreeDelete(t, cur->left);
  nodeTreeDelete(t, cur->right);
  free(cur);
}

void delete_rbtree(rbtree *t) {
  node_t *cur = t->root;

  nodeTreeDelete(t, cur);
  free(t->nil);
  t->nil = NULL;

  free(t);
  t = NULL;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *parent = t->nil;
  node_t *p = t->root;
  while (p != t->nil){
      parent = p;
      if (key < p -> key){
          p = p->left;
      }
      else{
          p = p->right;
      }
  }

  node_t *new_node = malloc(sizeof(node_t));
  new_node->key = key;
  new_node->left = t->nil;
  new_node->right = t->nil;
  new_node->color = RBTREE_RED;
  new_node->parent = parent;

  if (parent == t->nil)
      t->root = new_node;
  else if (key < parent->key)
      parent->left = new_node;
  else
      parent->right = new_node;
  
  

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  node_t *cur = t->root;
  while (cur != t->nil)
  {
    if (key == cur->key)
      return cur;
    else
      cur = (key < cur->key) ? cur->left : cur->right;
  }
  return NULL;
}

node_t *rbtree_min(const rbtree *t) {
  node_t *cur = t->root;

  while (cur->left != t->nil)
    cur = cur->left;
  return cur;
}

node_t *rbtree_max(const rbtree *t) {
  node_t *cur = t->root;
  while (cur->right != t->nil)
    cur = cur->right;
  return cur;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
