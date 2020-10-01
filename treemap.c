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
//  if(tree == NULL) return;

//TreeNode * aux = tree->root;
//TreeNode * parent = NULL;

//while (aux != NULL) {
 // if (tree ->lower_than(key,aux->key)){
   // aux = aux->left;
  //}else if (tree -> lower_than(aux -> key ,key)){
  //  aux = aux -> right;
  //}else{
  //  return;
  //}

//  }

}

TreeNode * minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




void * searchTreeMap(TreeMap * tree, void* key) {
  TreeNode * aux;
  aux = tree -> root;
  while(is_equal(tree, aux ->key,key)){
    printf("entro\n");
    if (aux == NULL) {
      return NULL;
    }
    tree -> current = aux;
    if (1==(tree -> lower_than(aux -> key,key))){

      aux = aux -> left;
    }else if(0==(tree -> lower_than(aux -> key,key))){

      aux = aux -> right;
    
    }else{
      tree -> current = aux;
      return tree-> current -> value;
    } 
  }
  tree -> current = aux;
  printf("salida por fuera\n");
  return tree-> current;
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
