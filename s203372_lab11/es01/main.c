#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#define N 10
int main()
{

    int choose, key, min, max, high, count, i, bst1, bst2;
    char name[26], file[26];
    FILE* f;
    BST *tree;

    tree = malloc(N*sizeof(BST));

    for(i=0; i<N; i++)
        tree[i] = NULL;

    i = 0;

help:
        printf("\nGESTIONE ALBERI BINARI DI RICERCA - BST CORRENTE [%d]\n\n", i);
        printf(" 1  - Creazione di un nuovo BST;\n");
        printf(" 2  - Inserimento in foglia di un nuovo elemento nel BST;\n");
        printf(" 3  - Inserimento in radice di un nuovo elemento nel BST;\n");
        printf(" 4  - Ricerca di un elemento (specificato dall'utente) nel BST;\n");
        printf(" 5  - Stampa dell'elemento minimo e massimo presenti nel BST;\n");
        printf(" 6  - Visualizzazione di tutti gli elementi presenti nel BST;\n");
        printf(" 7  - Calcolo dell'altezza dell'albero;\n");
        printf(" 8  - Calcolo del numero totale di nodi nell'albero;\n");
        printf(" 9  - Calcolo del numero di nodi foglia;\n");
        printf(" 10 - Salvataggio del BST su file;\n");
        printf(" 11 - Caricamento di un nuovo BST da file;\n");
        printf(" 12 - Cambia BST corrente;\n");
        printf(" 13 - Fondi due BST;\n");
        printf(" 14 - Svuota albero;\n");
        printf(" 15 - Esci.\n\n");

    while(choose!=15){

        printf("\nScelta(0 - 15; 0 = help): ");
        scanf("%d", &choose);

        switch(choose){

            case 0:
                system("cls");
                goto help;
            case 1:
                if(tree[i] == NULL)
                {
                    tree[i] = bst_init(tree[i]);
                    printf("Albero inizializzato con successo.\n");
                }
                else
                    printf("Albero gia' inizializzato!\n");
                break;
            case 2:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                {
                    printf("Inserisci chiave nuovo nodo: ");
                    scanf("%d", &key);
                    printf("Inserisci nome nuovo nodo: ");
                    scanf("%s", name);
                    bst_newleaf(tree[i], key, name);
                    printf("Elemento inserito con successo.\n");
                }
                break;
            case 3:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                {
                    printf("Inserisci chiave nuovo nodo: ");
                    scanf("%d", &key);
                    printf("Inserisci nome nuovo nodo: ");
                    scanf("%s", name);
                    tree[i] = bst_newroot(tree[i], key, name);
                    printf("Elemento inserito con successo.\n");
                }
                break;
            case 4:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                {
                    printf("Inserisci chiave nodo da cercare: ");
                    scanf("%d", &key);
                    bst_search(tree[i], key);
                }
                break;
            case 5:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                    {
                        min = bst_min(tree[i]);
                        max = bst_max(tree[i]);
                        printf("Elemento minimo dell'albero: %d\n", min);
                        printf("Elemento massimo dell'albero: %d\n", max);
                    }
                break;
            case 6:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                    {
                        printf("\n     Scegli opzione di visualizzazione:\n");
                        printf("     1 - Pre-order;\n");
                        printf("     2 - In-order;\n");
                        printf("     3 - Post-order;\n");
                        printf("Scelta: ");
                        scanf("%d", &choose);
                        switch(choose)
                        {
                            case 1:
                                bst_preorder(tree[i]);
                                break;
                            case 2:
                                bst_inorder(tree[i]);
                                break;
                            case 3:
                                bst_postorder(tree[i]);
                                break;
                            default:
                                printf("Inserisci valore corretto!\n");
                                break;
                        }
                    }
                break;
            case 7:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                    {
                       high =  bst_high(tree[i], 0, 0);
                       printf("Altezza dell'albero = %d", high);
                    }
                break;
            case 8:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                    {
                        count = bst_count(tree[i]);
                        printf("Numero di nodi nell'albero = %d", count);
                    }
                break;
            case 9:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                    {
                        count = bst_leafcount(tree[i]);
                        printf("Numero di nodi foglia nell'albero: = %d", count);
                    }
                break;
            case 10:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                {
                    printf("Nome file di salvataggio?: ");
                    scanf("%s", file);
                    f = fopen(file, "w");
                    bst_filesave(tree[i], f);
                    fclose(f);
                    printf("Salvataggio effettuato con successo.\n");
                }
                break;
            case 11:
                if (tree[i] == NULL)
                    printf("Albero non ancora inizializzato!\n");
                else
                {
                    f = fopen("new_bst.txt", "r");
                    bst_fileupload(tree[i], f);
                    printf("Caricamento albero da file avenuto con successo.\n");
                }
                break;
            case 12:
                printf("Inserire codice BST (0 - %d):", N);
                scanf("%d", &i);
                printf("BST selezionato con successo.\n");
                break;
            case 13:
                printf("Inserire codice BST ospitante (0 - %d):", N);
                scanf("%d", &bst1);
                printf("Inserire codice BST ospitato (0 - %d; -1 = Interrombi fusione):", N);
start_fusion:   scanf("%d", &bst2);
                if (bst2 == -1) break;
                f = fopen("bst_hosted.txt", "w");
                bst_filesave(tree[bst2], f);
                fclose(f);
                f = fopen("bst_hosted.txt", "r");
                bst_fileupload(tree[bst1], f);
                fclose(f);
                bst_free(tree[bst2]);
                free(tree[bst2]);
                tree[bst2] = NULL;
                printf("Inserire codice BST ospitato (0 - %d; -1 = Interrombi fusione):", N); goto start_fusion;
                printf("BST %d e %d fusi con successo.\n", bst1, bst2);
                break;
            case 14:
                bst_free(tree[i]);
                tree[i] = NULL;
                printf("Albero deallocato con successo.\n");
                break;
            default:
                printf("Inserisci valore corretto!\n");
                break;
        }

    }

    return 0;
}
