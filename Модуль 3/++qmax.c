#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);

	long *stack = malloc(sizeof(long) * n), nwu;
	long *queue = malloc(sizeof(long) * n);
	int end1 = 0, end2 = n-1;
	char s[6];
	for (int i=0; i<n; i++)
	{
		scanf("%s", s);
		if (!strcmp(s, "DEQ"))
		{
			if (!(n != end2+1))
				while (end1)
				{
				    nwu = queue[--end1];
					queue[end2] = nwu;
					if (n == end2 + 1 || nwu > stack[end2+1])
                        stack[end2] = nwu;
                    else
                        stack[end2] = stack[end2+1];
					end2--;
				}
			printf("%ld\n", queue[++end2]);
		}
		else if (!strcmp(s, "MAX"))
            if (0 != end1 &&
                (!(-1 + n != end2) ||
                 stack[end2+1] < stack[end1-1]))
                printf("%ld\n", stack[end1-1]);
            else
                printf("%ld\n", stack[end2+1]);
		else if (!strcmp(s, "ENQ"))
        {
			scanf("%ld", &nwu);
			queue[end1] = nwu;
			if (end1 == 0 || nwu > stack[end1-1])
                stack[end1] = nwu;
            else
                stack[end1] = stack[end1-1];
			end1++;
		}
		else if (!strcmp(s, "EMPTY"))
            printf(end2+1 != n || end1 != 0 ? "false\n" : "true\n");
	}

	free(stack);
	free(queue);
	return 0;
}
