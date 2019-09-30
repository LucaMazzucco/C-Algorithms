#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct binarysearchtree *BST;

BST bst_init(BST tree);
void bst_newleaf(BST tree, int key, char *name);
BST bst_newroot(BST tree, int key, char *name);
BST bst_rotL(BST tree);
BST bst_rotR(BST tree);
void bst_search(BST tree, int key);
int bst_min(BST tree);
int bst_max(BST tree);
void bst_preorder(BST tree);
void bst_inorder(BST tree);
void bst_postorder(BST tree);
int bst_high(BST tree, int high_best, int high);
int bst_count(BST tree);
int bst_leafcount(BST tree);
void bst_filesave(BST tree, FILE*f);
void bst_fileupload(BST tree, FILE *f);
void bst_free(BST tree);
#endif // BST_H_INCLUDED
