#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "item.h"

struct binarysearchtree{
    ITEM item;
    BST r;
    BST l;
};

BST bst_init(BST tree){

    tree = malloc(sizeof(struct binarysearchtree));
    tree->item = NULL;
    tree->l = NULL;
    tree->r = NULL;
    return tree;
}

void bst_newleaf(BST tree, int key, char *name)
{

    if(tree->item == NULL)
    {
        tree->item = item_new(key, name);
        tree->l = bst_init(tree->l);
        tree->r = bst_init(tree->r);
        return;
    }
    else
    {
        if (item_getkey(tree->item)>= key)
            bst_newleaf(tree->l, key, name);
        else
            bst_newleaf(tree->r, key, name);
    }

    return;
}

BST bst_newroot(BST tree, int key, char *name){

    if(tree->l == NULL && tree->r == NULL)
    {
        tree->item = item_new(key, name);
        tree->l = bst_init(tree->l);
        tree->r = bst_init(tree->r);
        return tree;
    }
    else
    {
        if (item_getkey(tree->item)>= key)
        {
            tree->l = bst_newroot(tree->l, key, name);
            tree = bst_rotR(tree);
        }
        else
        {
            tree->r = bst_newroot(tree->r, key, name);
            tree = bst_rotL(tree);
        }
    }
    return tree;
}

BST bst_rotL(BST tree)
{
    BST x;
    x = tree->r;
    tree->r = x->l;
    x->l = tree;

    return x;
}
BST bst_rotR(BST tree)
{
    BST x;
    x = tree->l;
    tree->l = x->r;
    x->r = tree;

    return x;
}

void bst_search(BST tree, int key){

    if(tree->item == NULL) return;
    if(item_getkey(tree->item) == key)
    {
        printf("Elemento trovato.");
        return;
    }
    if(item_getkey(tree->item)>key)
        bst_search(tree->l, key);
    else
        bst_search(tree->r, key);

    return;
}

int bst_min(BST tree)
{
    if(tree->l->item == NULL)
        return item_getkey(tree->item);
    return bst_min(tree->l);
}
int bst_max(BST tree)
{
    if(tree->r->item == NULL)
        return item_getkey(tree->item);
    return bst_max(tree->r);
}

void bst_preorder(BST tree)
{

    if(tree->item == NULL)
        return;

    item_visit(tree->item);
    bst_preorder(tree->l);
    bst_preorder(tree->r);


    return;
}
void bst_inorder(BST tree)
{
    if(tree->item == NULL)
        return;

    bst_inorder(tree->l);
    item_visit(tree->item);
    bst_inorder(tree->r);

    return;
}
void bst_postorder(BST tree)
{
    if(tree->item == NULL)
        return;

    bst_postorder(tree->l);
    bst_postorder(tree->r);
    item_visit(tree->item);

    return;
}

int bst_high(BST tree, int high_best, int high){

    if(tree->item == NULL){
        if(high>high_best)
            high_best = high;
        return high_best;
    }
    high_best = bst_high(tree->l, high_best, high+1);
    high_best = bst_high(tree->r, high_best, high+1);
    return high_best;
}

int bst_count(BST tree)
{
    if(tree->item == NULL)
        return 0;
    return bst_count(tree->l) + bst_count(tree->r) + 1;
}

int bst_leafcount(BST tree){

    if(tree->item == NULL)
        return 0;
    if((tree->l->item == NULL) && (tree->r->item == NULL))
        return 1;
    return bst_leafcount(tree->l) + bst_leafcount(tree->r);
}
void bst_filesave(BST tree, FILE*f){

    if(tree->item == NULL)
        return;

    bst_filesave(tree->l, f);
    item_filesave(tree->item, f);
    bst_filesave(tree->r, f);

    return;

}

void bst_fileupload(BST tree, FILE *f){

    int key;
    char name[26];

    while(!feof(f)){
        fscanf(f, "%d%s", &key, name);
        bst_newleaf(tree, key, name);
    }
    fclose(f);
}

void bst_free(BST tree){

    if(tree->item == NULL){
        free(tree);
        return;
    }

    bst_free(tree->l);
    bst_free(tree->r);
    free(tree);
    return;
}
