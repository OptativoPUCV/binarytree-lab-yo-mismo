#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    void* key;
    void * value;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->key = key;
    new->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
  TreeMap * tree = (TreeMap *)malloc(sizeof(TreeMap));
  tree -> lower_than = lower_than;

    return tree;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
  if(tree == NULL) return;

  TreeNode * aux = tree->root;
  TreeNode * parent = NULL;

  while (aux != NULL) {
    parent = aux;

    if (tree ->lower_than(key,aux->key)){
      aux = aux->left;
    }else if (tree -> lower_than(aux -> key ,key)){
      aux = aux -> right;
    }else{
      return;
    }
  }
  TreeNode * nuevo = createTreeNode(key,value);
  nuevo -> parent = parent;
  if(parent == NULL){
    tree -> root = nuevo;
  }else if(tree -> lower_than(nuevo->key,parent->key)){
    parent -> left = nuevo;
  }else{
    parent -> right = nuevo;
  }
  tree ->current = nuevo;
}


TreeNode * minimum(TreeNode * x){
  while(x ->left != NULL){
    x = x -> left;
  }

  return x;
}


void removeNode(TreeMap * tree, TreeNode* node) {

  if((node ->left == NULL) && (node ->right == NULL)){
    tree -> current = node -> parent;
    if(tree -> current -> left == node){
      tree -> current -> left = NULL;
    }
  

  }else if((node ->left != NULL) && (node ->right != NULL)){
    printf("Xd\n");
  }else{
    tree -> current = node -> parent;
    if (node -> right != NULL){
      
        tree -> current -> left = node -> right;

    }else{
      if (tree -> current -> right != NULL){
        tree -> current -> right = node -> left;
        tree->current -> right-> parent = tree -> current;
      }else{
        tree -> current -> left = node -> left;
        tree->current -> left-> parent = tree -> current;
      }
    }

  }

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




void * searchTreeMap(TreeMap * tree, void* key) 
{
  TreeNode * aux;
  aux = tree -> root;
  int i= 1;
  while(i ==1){
    if (aux == NULL) return NULL;

    tree -> current = aux;
    if(is_equal(tree, aux ->key,key)){
      return aux -> value;
    }else if (0==tree -> lower_than(aux -> key,key)){

      aux = aux -> left;

    }else if(1==tree -> lower_than(aux -> key,key)){

      aux = aux -> right;
    }
  }
  return NULL;
}


void * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

void * firstTreeMap(TreeMap * tree) {
    return NULL;
}

void * nextTreeMap(TreeMap * tree) {
    return NULL;
}
