#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int mergesort(int a[], int l, int r);
int mergesort2(char **a, int l, int r);
int mergemio(int a[], int l, int q, int r);
int mergemio2(char **A, int p, int q, int r);
int stampa_array(int V[], int n);
int stampa_array2(char **V, int n);

int main(int argc, char *argv[])
{

    FILE*f;
    char stri[51], **vs;
    int i, l, j, flag = 1, *vn;

    if ( (f = fopen(argv[1], "r"))==NULL)
        return -1;
    fscanf(f, "%d", &j);
    fscanf(f, "%s", stri);
    l = strlen(stri);
    for (i=0; i<l;i++)
        if (isdigit(stri[i])==0)
            flag = 0;
    rewind(f);
    fscanf(f, "%d", &j);
    if (flag == 1){
        vn = malloc(j*sizeof(int));
        for (i=0; i<j; i++)
            fscanf(f, "%d", &vn[i]);
        mergesort(vn, 0, j-1);
        stampa_array(vn, j);
    }
    else{
        vs = malloc(j*sizeof(char *));
        for (i=0; i<j; i++){
            vs[i] = malloc(51*sizeof(char));
            fscanf(f, "%s", vs[i]);
        }
        mergesort2(vs, 0, j-1);
        stampa_array2(vs, j);
    }
    return 0;
}
int mergesort(int a[], int l, int r){
    int q;
    if (l<r){
        q = (l+r)/2;
        mergesort(a, l, q);
        mergesort(a, q+1, r);
        mergemio(a, l, q, r);
    }
    return 0;
}
int mergesort2(char **a, int l, int r){
    int q;
    if (l<r){
        q = (l+r)/2;
        mergesort2(a, l, q);
        mergesort2(a, q+1, r);
        mergemio2(a, l, q, r);
    }
    return 0;
}
int mergemio(int A[], int p, int q, int r) {
  int i, j, k, B[100];

  i = p;
  j = q+1;
  k = 0;
  while (i<=q && j<=r) {
    if (A[i]<A[j]) {
      B[k] = A[i];
      i++;
    } else {
      B[k] = A[j];
      j++;
    }
    k++;
  }
  while (i<=q) {
    B[k] = A[i];
    i++;
    k++;
  }
  while (j<=r) {
    B[k] = A[j];
    j++;
    k++;
 }
  for (k=p; k<=r; k++)
    A[k] = B[k-p];
  return 0;
}
int mergemio2(char **A, int p, int q, int r) {
  int i, j, k;
  char *B[100];
  i = p;
  j = q+1;
  k = 0;
  while (i<=q && j<=r) {
    if (strcmp(A[i],A[j])<=0) {
      B[k] = A[i];
      i++;
    } else {
      B[k] = A[j];
      j++;
    }
    k++;
  }
  while (i<=q) {
    B[k] = A[i];
    i++;
    k++;
  }
  while (j<=r) {
    B[k] = A[j];
    j++;
    k++;
 }
  for (k=p; k<=r; k++)
    A[k] = B[k-p];
  return 0;
}
int stampa_array(int V[], int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
  return 0;
}
int stampa_array2(char **V, int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%s ", V[i]);
  }
  printf("\n");
  return 0;
}
