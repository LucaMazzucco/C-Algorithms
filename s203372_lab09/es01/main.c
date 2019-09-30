#include <stdio.h>
#include <stdlib.h>

int sum_best=0, *mark_best, flag =0, count=0, n_bag=0, n_bag_min;
float weight_part=0;

struct luggage{
        char name[20];
        float weight;
        int value;
    }*bag;

void disp(int pos, float weight_tot, int *mark, int *sol, int sum_value, int n, float weight_max);

int main(int argc, char*argv[])
{
    FILE *f;
    int n, i, *mark,*sol, c =0;
    float weight_max = 0, weight_min = 0;

    if ((f=fopen(argv[1], "r"))==NULL) return -1;
    fscanf(f, "%d", &n);

    n_bag_min = n;
    bag = malloc(n*sizeof(struct luggage));
    mark = malloc(n*sizeof(int));
    mark_best = malloc(n*sizeof(int));
    sol = malloc(n*sizeof(int));

    for(i=0; i<n; i++){
        fscanf(f, "%s", bag[i].name);
        fscanf(f, "%f", &bag[i].weight);
        if(bag[i].weight>weight_min)
            weight_min = bag[i].weight;
        fscanf(f, "%d", &bag[i].value);
        mark[i] = 0;
    }
weight:
    printf("Inserire peso massimo bagaglio a mano: ");
    scanf("%f", &weight_max);
    if(weight_max<weight_min){
        printf("\nPeso inserito minore del collo piu' pesante!\n");
        goto weight;
    }


    disp(0, 0, mark, sol, 0, n, weight_max);
    printf("Miglior disposizione possibile per bagaglio a mano da %.2f kg:\n\n", weight_max);
    for(i=0; i<n; i++){
        if(mark_best[i]==1){
            printf("   %d) ",count+1);
            printf("%s ", bag[i].name);
            printf("%f ", bag[i].weight);
            printf("%d \n", bag[i].value);
            count++;
        }
    }

    printf("Valore totale: %d", sum_best);
    flag = 1;

    disp(0, 0, mark, sol, 0, n, weight_max);
    weight_part =0;
    n_bag=0;
    printf("\n\nMiglior disposizione possibile per bagagli restanti da %.2f kg:\n1)\n\n", weight_max);
    for(i=0; i<n-count; i++){
        if(mark_best[sol[i]]==1){
            weight_part += bag[sol[i]].weight;
            if(weight_part > weight_max){
                printf("\n");
                weight_part =0;
                n_bag++;
                printf("\n%d)\n\n", n_bag+1);
                c = 0;
            }

            printf("   %d) %s ", c+1, bag[sol[i]].name);
            printf("%f ", bag[sol[i]].weight);
            printf("%d \n", bag[sol[i]].value);
            c++;
        }
    }
    printf("Numero valigie: %d", n_bag+1);
    return 0;
}

void disp(int pos, float weight_tot, int *mark, int *sol, int sum_value, int n, float weight_max){

    int i,j;
    if(flag ==0){
        if(weight_tot<=weight_max)
        {
            if(sum_value>sum_best){
                sum_best = sum_value;
                for(i=0; i<n; i++)
                    mark_best[i] = mark[i];
            }
        }
        else
            return;
    }
    else{
        if(pos>=n-count){
            for(j=0; j<pos; j++){
                if(mark[sol[j]] == 1){
                    if(weight_part<=weight_max)
                        weight_part += bag[sol[j]].weight;
                    else{
                        n_bag++;
                        j--;
                        weight_part = 0;
                    }
                }
            }

            if(n_bag < n_bag_min)
                for(j=0; j<n; j++)
                    mark_best[j] = mark[j];
            n_bag = 0;
            weight_part =0;
            return;
        }
    }
    for(i=0; i<n; i++)
        if(mark[i]==0){
            mark[i]=1;
            sol[pos] = i;
            disp(pos+1, weight_tot + bag[i].weight, mark, sol, sum_value + bag[i].value, n, weight_max);
            mark[i]=0;
            }
    return;
}
