#include <stdio.h>
#include <stdlib.h>
#include "Libvar.h"
#include "libfifo.h"

utente *elemento, *head;
int n, i, flag = 0;
int creazione(){
    if (flag == 1)
        for (elemento = head, j=0; j<n; j++, free(elemento), elemento = elemento->next);
    flag = 1;
    head = (elemento = malloc(sizeof(utente)));
    printf("Inserisci lunghezza coda: ");
    scanf("%d", &n);
    for (i = 1; i<n; i++, elemento = (elemento->next = malloc(sizeof(utente))));
    elemento->next = head;
    i=0;
    elemento = head;
    printf("Lista creata con successo.\n");
return 0;
}
int stampa(){
    if ( flag == 0){
        printf("Creare prima una coda!\n");
        return -1;}
    printf("\nNumero di dati in coda: %d\n", n);
return 0;
}
int inserimento(){
    if ( flag == 0){
        printf("Creare prima una coda!\n");
        return -1;}
    if (i < n){
        printf("Inserisci nome: ");
        scanf("%s", elemento->nome);
        printf("Inserisci numero: ");
        scanf("%d", &elemento->num);
        elemento = elemento->next;
        i++;
    }
    else printf("Spazio esaurito!");
    return 0;
}
int estrazione(){
    if ( flag == 0){
        printf("Creare prima una coda!\n");
        return -1;}
    int j;
    for (j=0,elemento = head; j<i; j++, elemento = elemento->next);
    i--;
    printf("\nElemento in coda eliminato con successo!\n");
return 0;
}
int visual(){
    if ( flag == 0){
        printf("Creare prima una coda!\n");
        return -1;}
    int j;
    printf("Elenco dati della coda:\n");
    for(elemento = head, j=0; j<i; j++, printf("%s   %d\n", elemento->nome, elemento->num), elemento = elemento->next);
return 0;
}
int salva(){
    if ( flag == 0){
        printf("Creare prima una coda!\n");
        return -1;}
    FILE *f;
    int j;
    if ((f=fopen("Elenco.txt", "w"))==NULL) return -1;
    for(j=0, elemento = head; j<i; j++, fprintf(f,"%s   %d\n", elemento->nome, elemento->num), elemento = elemento->next);
    printf("\nLista salvata con successo!\n");
return 0;
}
int carica(char argv[]){
    if ( flag == 0){
        printf("Creare prima una coda!\n");
        return -1;}
    int scelta,j;
    FILE *f;
    if (( f=fopen(argv, "r"))==NULL) return -1;
    printf("     Scegli opzione per il caricameto: \n     1 - Sovvrascrivi coda;\n     2 - Carica a seguire.\n");
    scanf("%d", &scelta);
    switch(scelta){
        case 1:
            for (elemento = head, j=0; j<n; j++, free(elemento), elemento = elemento->next);
            head = (elemento = malloc(sizeof(utente)));
            for (i = 0; i<n&&!feof(f); i++, fscanf(f, "%s%d", elemento->nome, &elemento->num),  elemento = (elemento->next = malloc(sizeof(utente))));
            break;
        case 2:
            for (;i<n&&!feof(f); i++, fscanf(f, "%s%d", elemento->nome, &elemento->num),  elemento = (elemento->next = malloc(sizeof(utente))));
            break;
        default: printf("Valore inserito non corretto!\n");
    }
return 0;
}
