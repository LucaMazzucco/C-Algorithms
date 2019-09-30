#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct node{
    int key;
    struct node* children[N];
}*NODO;

int level =-1, j;


void visitLevelByLevel(struct node *root, int l1, int l2);

int main()
{
    int L1 = 5;
    int L2 = 10;
    j = L1;
    NODO  head;
    head = malloc(sizeof(struct node));

    ///CARICAMENTO DATI ALBERO

    visitLevelByLevel(head, L1, L2);

    return 0;
}

void visitLevelByLevel(struct node *root, int l1, int l2)
{
    int i;
    if(level == j)
    {
        printf("%d", root->key);
        return;
    }

    level++;

    for(i=0; i<N; i++)
    {
        visitLevelByLevel(root->children[i], l1, l2);
    }
    level--;

    if(i == N && level == 0 && j<=l2)
    {
        j++;
        visitLevelByLevel(root, l1, l2);
    }

    return;
}
