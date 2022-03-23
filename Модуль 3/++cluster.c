#include <stdio.h>

#define BALLANCE\
			for (i=0;;)\
			{\
				l = 2 * i + 1; r = l + 1; j = i;\
				if (l<cpq && clstrs[i]>clstrs[l]) i = l;\
				if (r<cpq && clstrs[i]>clstrs[r]) i = r;\
				if (i == j) break;\
				buf = clstrs[i];\
				clstrs[i] = clstrs[j];\
				clstrs[j] = buf;\
			}

int main(int argc, char **argv)
{
	long long n, m, t1, t2, i, j, l, r, buf, cpq = 0;
	scanf("%lld %lld", &n, &m);
	long long clstrs[n];
	for (; m; m--)
	{
		scanf("%lld %lld", &t1, &t2);
		if (cpq != n)
		{
		    i = cpq++;
			clstrs[i] = t1 + t2;
			while (i>0 && clstrs[(i-1)/2]>clstrs[i])
			{
				buf = clstrs[i];
				clstrs[i] = clstrs[(i-1)/2];
				clstrs[(i-1)/2] = buf;
				i = (i-1)/2;
			}
		}
		else
		{
			if (t1 > clstrs[0])
                clstrs[0] = t2 + t1;
            else
                clstrs[0] += t2;
			BALLANCE
		}
	}

	while (--cpq > 0)
    {
        clstrs[0] = clstrs[cpq];
        BALLANCE
    }

	printf("%lld\n", clstrs[0]);
	return 0;
}
