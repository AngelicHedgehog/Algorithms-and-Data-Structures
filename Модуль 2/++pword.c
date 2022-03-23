#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *S = argv[1], *T = argv[2];
    int len_S = strlen(S),
        len_T = strlen(T);

    int len_ST = len_S + len_T;
    char ST[len_ST];
    for (int i=0; i<len_S; i++) ST[i] = S[i];
    for (int i=0; i<len_T; i++) ST[i+len_S] = T[i];

    int pi[len_ST], t = 0, i;
    pi[0] = 0;
    for (i=1; i<len_ST; i++)
    {
        while (t > 0 && ST[t] != ST[i])
            t = pi[t - 1];
        if (ST[t] == ST[i])
            t++;
        pi[i] = t;
        if (i >= len_S && !t) break;
    }
    printf(i == len_ST ? "yes\n" : "no\n");
    return 0;
}
