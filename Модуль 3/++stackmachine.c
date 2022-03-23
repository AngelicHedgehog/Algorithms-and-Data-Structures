#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int n = 3, i = 0;
    scanf("%d", &n);

    long long stack[n+1];
    char command[6];

    for (; n; n--)
    {
        scanf("%s", &command);
        if (!strcmp(command, "CONST"))
        {
            scanf("%lld", &stack[i]);
            i++;
        }
        else if (!strcmp(command, "ADD"))
        {
            stack[i-2] += stack[i-1];
            i--;
        }
        else if (!strcmp(command, "SUB"))
        {
            stack[i-2] = stack[i-1] - stack[i-2];
            i--;
        }
        else if (!strcmp(command, "MUL"))
        {
            stack[i-2] *= stack[i-1];
            i--;
        }
        else if (!strcmp(command, "DIV"))
        {
            stack[i-2] = stack[i-1] / stack[i-2];
            i--;
        }
        else if (!strcmp(command, "MAX"))
        {
            if (stack[i-1] > stack[i-2])
                stack[i-2] = stack[i-1];
            i--;
        }
        else if (!strcmp(command, "MIN"))
        {
            if (stack[i-1] < stack[i-2])
                stack[i-2] = stack[i-1];
            i--;
        }
        else if (!strcmp(command, "NEG"))
        {
            stack[i-1] = -stack[i-1];
        }
        else if (!strcmp(command, "DUP"))
        {
            stack[i] = stack[i-1];
            i++;
        }
        else if (!strcmp(command, "SWAP"))
        {
            stack[i] = stack[i-1];
            stack[i-1] = stack[i-2];
            stack[i-2] = stack[i];
        }
        else
        {
            n++;
        }

    }
    printf("%lld ", stack[i-1]);
    return 0;
}
