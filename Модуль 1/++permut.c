#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    int a[8]={0}, b[8]={0}, i, j;
    long long A[8], B[8];

    for (i = 0; i<8; i++) scanf("%lld", &A[i]);
    for (i = 0; i<8; i++) scanf("%lld", &B[i]);

    for (i = 0; i<8; i++)
        for (j = 0; j<8; j++)
        {
            if (A[i] == B[j])
            {
                a[i] += 1;
                b[j] += 1;
            }
        }

    int aa[8]={0}, bb[8]={0}, rez = 0;
    for (i = 0; i<8; i++)
    {
        if (a[i] == 0 | b[i] == 0)
        {
            rez = 1;
            break;
        }
        aa[a[i] - 1] += 1;
        bb[b[i] - 1] += 1;
    }
    for (i = 0; i<8; i++)
        rez += aa[i] % (i + 1) + bb[i] % (i + 1);

    printf(rez ? "no" : "yes");
    return 0;
}

