#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE* f;
    struct coord {
    int x,y;
    struct coord *succ;
    }*p,*q,*r,*max1,*max2,*min1,*min2;
    int i=0, j,k, somma,c=0;
    float mind, maxd, dist, distmin;
    if ((f = fopen("Coord.txt", "r"))==NULL)
        printf("Impossibile aprire il file!");
    else{
        printf("Inserire la distanza minima da conteggiare: ");
        scanf("%f", &distmin);

        p = malloc(sizeof *p);
        q = p;
        r = q;
        while(!feof(f)){
            fscanf(f, "%d%d", &p->x, &p->y);
            i++;
            p = (p->succ = malloc(sizeof *p));
        }
    fclose(f);
    dist =sqrt(  pow(((q->x)-(r->succ->x)),2) + pow(((q->y)-(r->succ->y)),2));
    if (dist<=distmin)
        c++;
    mind = dist;
    maxd = dist;
    min1 = q;
    min2 = r->succ;
    max1 = q;
    max2 = r->succ;

    for(k=0;k<i-1;k++){
    for(j=0;j<i-1-k;j++){

        dist =sqrt(  pow(((q->x)-(r->succ->x)),2) + pow(((q->y)-(r->succ->y)),2));
        if (dist<=distmin)
            c++;
        if (dist<mind){
            mind = dist;
            min1 = q;
            min2 = r->succ;}
        if (dist>maxd){
            maxd=dist;
            max1 = q;
            max2 = r->succ;
        }
        r = r->succ;
    }
    q = q->succ;
    r = q;
    }
    printf("Dist min: %5.2f punti 1) %d %d; 2) %d %d;\n", mind, min1->x, min1->y, min2->x, min2->y);
    printf("Dist max: %5.2f punti 1) %d %d; 2) %d %d;\n", maxd, max1->x, max1->y, max2->x, max2->y);
    printf("Segmenti con distanza minima a %.2f: %d", distmin, c);
    }

    return 0;
}
