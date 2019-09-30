#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[31], s1[31];
    int i=0, j, x,k;

    printf("Stringa? ");
        scanf("%s", s);
    while (strcmp(s, "stop")!=0){


            x = strlen(s);
        for(i=1; i<=x; i++){
            j=0;
            for (k=0; k< 31; k++){
            s1[k]='\0';}
            strncpy(s1, s, i);
            while(strstr(s,s1)!=NULL){

                strncat(s1,s,i);
                j++;
            }
        if (j*i==x&&j>1){
            printf("La stringa e' periodica di periodo %d", i);
            break;}
        }
        if(j*i!=x || j==1)
            printf("La stringa non e' periodica");
        printf("\nStringa? ");
        scanf("%s", s);


    }

    return 0;
}
