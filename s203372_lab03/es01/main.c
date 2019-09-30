#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE* f;
    struct coord {
    int x,y;
    float dist;
    };

    struct coord *p, temp;

    int i,j,k, c=0, coordinate[8];
    float mind, maxd, distmin, distan;

    if ((f = fopen("Coord.txt", "r"))==NULL)
        printf("Impossibile aprire il file!");
    else{
        printf("Inserire la distanza minima da conteggiare: ");
        scanf("%f", &distmin);

        for (i=0; fscanf(f, "%*d%*d")!=EOF;i++){}
        rewind(f);
        p = malloc(i*sizeof(struct coord));
        for(j=0; j<i; j++){
            fscanf(f, "%d%d", &p[j].x, &p[j].y);
            p[j].dist=sqrt((pow(p[j].x, 2))+(pow(p[j].y, 2)));
        }
        fclose(f);
        distan = sqrt((powf((p[0].x-p[1].x), 2))+(powf((p[0].y-p[1].y),2)));
        mind = distan;
        maxd = distan;
        for(j=0; j<i-1; j++){
            for(k=j+1; k<i; k++){
                distan = sqrt((powf((p[j].x-p[k].x), 2))+(powf((p[j].y-p[k].y),2)));
                if(distan<mind){
                    mind = distan;
                    coordinate[0]=p[j].x;
                    coordinate[1]=p[j].y;
                    coordinate[2]=p[k].x;
                    coordinate[3]=p[k].y;}
                if(distan>maxd){
                    maxd = distan;
                    coordinate[4]=p[j].x;
                    coordinate[5]=p[j].y;
                    coordinate[6]=p[k].x;
                    coordinate[7]=p[k].y;}
                if(distan<distmin)
                    c++;
            }
        }
    }
    printf("Il numero di segmenti inferiori a %.2f e': %d\n",distmin, c);
    printf("Distanza minima tra i segmenti: %.2f\n", mind);
    printf("Punti: 1) %d %d  2) %d %d\n", coordinate[0], coordinate[1], coordinate[2], coordinate[3]);
    printf("Distanza massima tra i segmenti: %.2f\n", maxd);
    printf("Punti: 1) %d %d  2) %d %d\n", coordinate[4], coordinate[5], coordinate[6], coordinate[7]);
    for (k=0; k<i; k++)
        for (j=0; j<i; j++)
            if (p[k].dist<p[j].dist)
            {
                temp=p[k];
                p[k]=p[j];
                p[j]=temp;
            }
    if ((f = fopen("ord.txt", "w"))==NULL)
        printf("Impossibile aprire il file!");
    else
        for (k=0; k<i; k++)
            fprintf(f,"%.2f\n", p[k].dist);
    fclose(f);
        free(p);
}
