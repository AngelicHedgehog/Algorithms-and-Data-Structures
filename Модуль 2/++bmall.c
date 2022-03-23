#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Delta1(int *del1, char *S, int len_S, int size)
{
    for (int a=0; a<size; a++)
        del1[a] = len_S;
    for (int j=0; j<len_S; j++)
        del1[S[j]-33] = len_S - j - 1;
}

void Suffix(int *del, char *S, int len_S)
{
    int t = len_S - 1;
    del[len_S - 1] = t;
    for (int i=len_S-2; i>=0; i--)
    {
        while (t < len_S - 1 && S[t] != S[i])
            t = del[t + 1];
        if (S[t] == S[i]) t--;
        del[i] = t;
    }
}

void Delta2(int *del2, char *S, int len_S)
{
    int del[len_S], t;
    Suffix(del, S, len_S);
    t = del[0];

    for (int i=0; i<len_S; i++)
    {
        for (; t<i; t=del[t+1]);
        del2[i] = t + len_S - i;
    }

    for (int i=0; i<len_S-1; i++)
        for (t=i; t<len_S-1;)
        {
            t = del[t + 1];
            if (S[i] != S[t])
                del2[t] = len_S - i - 1;
        }
}

int main(int argc, char **argv)
{
    char *S = argv[1], *T = argv[2];
    int len_S = strlen(S), len_T = strlen(T);

    int del1[94], del2[len_S], k = len_S - 1, i;
    Delta1(del1, S, len_S, 94);
    Delta2(del2, S, len_S);

    while (k < len_T)
    {
        for (i=len_S-1; T[k]==S[i]; i--)
        {
            if (!i) {printf("%d ", k); break;}
            k--;
        }
        k += del1[T[k]-33] > del2[i] ? del1[T[k]-33] : del2[i];
    }

    return 0;
}
