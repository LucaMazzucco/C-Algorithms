#include <stdio.h>
#include <stdlib.h>

void eraseDuplicate(char*str);

int main()
{
    char str[15];
    scanf("%s", str);
    eraseDuplicate(str);

    return 0;
}

void eraseDuplicate(char*str)
{
    int i = 1, j=0, n=0, flag =0;

    char *str2 = malloc(sizeof(str));
    str2[0] = str[0];

    while(str[i]!='\0')
    {
        j = n;
        flag = 0;
        while(j>=0)
        {
            if(str[i]==str2[j])
                flag = 1;
            j--;
        }
        if(flag==0)
        {
            n++;
            str2[n] = str[i];
        }
        i++;
    }
    n++;
    str2[n] = '\0';
    printf("%s", str2);
    return;
}
