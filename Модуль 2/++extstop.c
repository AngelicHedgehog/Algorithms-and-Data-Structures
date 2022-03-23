#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Delta1(int **del1, char *S, int len_S, int size)
{
    for (int a=0; a<len_S; a++)
    {
        del1[a] = (int*)malloc(sizeof(int)*size);
        for (int b=0; b<size; b++)
            del1[a][b] = len_S;
    }
    for (int j=len_S-1; j>=0; j--)
        for (int i=j+1; i<len_S && del1[i][S[j]-33]>i-j; i++)
            del1[i][S[j]-33] = i - j;
}

int main(int argc, char **argv)
{
    char *S = argv[1], *T = argv[2];
    int len_S = strlen(S), len_T = strlen(T);

    int **del1 = (int**)malloc(sizeof(int*)*len_S), k = len_S - 1, i;
    Delta1(del1, S, len_S, 94);
    while (k < len_T)
    {
        for (i=len_S-1; T[k]==S[i]; i--, k--)
            if (!i)
            {
                printf("%d\n", k);
                for (i=0; i<len_S; i++) free(del1[i]);
                free(del1);
                return 0;
            }
        k += del1[i][T[k]-33];
    }
    printf("%d\n", len_T);
    for (i=0; i<len_S; i++) free(del1[i]);
    free(del1);
    return 0;
}
