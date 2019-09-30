#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE*f;
    int x;
    char s[20], diz[20][20], c;
    f = fopen("dizionario.txt", "r");
    if (f == NULL)
        printf("Impossibile aprire il file");
    else
    {
        while(!feof(f)){
            fscanf(f,"%d%s",&x, s);
            strcpy(diz[x], s);
        }
    fclose(f);

    f = fopen("codificato.txt", "r");
    if (f == NULL)
        printf("Impossibile aprire il file");
    else
    {
        while(!feof(f)){
            fscanf(f,"%c", &c);
            if (c=='$'){
                fscanf(f,"%d", &x);
                strcpy(s, diz[x]);
                printf("%s", s);
            }
            else
            printf("%c", c);
        }
    }
    }

    return 0;
}
