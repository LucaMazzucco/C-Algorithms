#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void disp(int pos, char**set, char*sigla, int n, FILE*f);

int main(int argc, char*argv[])
{
    FILE*f;
    int n, i;
    char **set, *sigla;
    if (( f = fopen(argv[1], "r"))== NULL) return -1;

    fscanf(f, "%d", &n);
    set = malloc(n*sizeof(char*));
    sigla = malloc(n*sizeof(char));
    for(i=0; i<n; i++)
    {
        set[i] = malloc(10*sizeof(char));
        fscanf(f, "%s", set[i]);
    }

    fclose(f);
    if (( f = fopen(argv[2], "w"))== NULL) return -1;

    disp(0, set, sigla, n, f);

    fclose(f);

    return 0;
}


void disp(int pos, char**set, char*sigla, int n, FILE*f)
{
    int i;
    if (pos==n)
    {
        fprintf(f, "%s\n", sigla);
        return;
    }
    for(i=0; i<strlen(set[pos]); i++)
    {
        sigla[pos] = set[pos][i];
        disp(pos+1, set, sigla, n, f);
    }


    return;
}
