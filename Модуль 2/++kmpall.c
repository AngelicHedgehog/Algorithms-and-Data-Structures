#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Prefix(int *pi, char *S, int len_S)
{
    int t = 0;
    pi[0] = 0;
    for (int i=1; i<len_S; i++)
    {
        while (t > 0 && S[t] != S[i])
            t = pi[t - 1];
        if (S[t] == S[i])
            t++;
        pi[i] = t;
    }
}

int main(int argc, char **argv)
{
    char *S = argv[1], *T = argv[2];
    int len_S = strlen(S), len_T = strlen(T);

    int pi[len_S], q = 0;
    Prefix(pi, S, len_S);

    for (int k=0; k<len_T; k++)
    {
        while (q > 0 && S[q] != T[k])
            q = pi[q - 1];
        if (S[q] == T[k]) q++;
        if (q == len_S)
            printf("%d ", k - len_S + 1);
    }

    return 0;
}
