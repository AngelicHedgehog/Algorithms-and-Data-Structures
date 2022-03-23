#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

struct Slist {
	char *str;
	struct Slist **next;
	long k;
	long *span;
};
struct Slist * suc(struct Slist * list)
{
	return list->next[0];
}
struct Slist ** scip(struct Slist * list, long m, long k, struct Slist **p)
{
	struct Slist * r = list;
	long i = m - 1;
	while (i>=0)
	{
		while ((r->next[i] != NULL) && r->next[i]->k < k)
		{
			r = r->next[i];
		}
		p[i] = r;
		i--;
	}
	return p;
}
char * look(struct Slist *list, long m, long k)
{
	struct Slist ** p = malloc(sizeof(struct Slist*)*m);
	scip(list, m, k, p);
	struct Slist * r = suc(p[0]);
	free(p);
	return r->str;
}
struct Slist * ins(struct Slist * list, long m, long k, char* c)
{
	struct Slist ** p = malloc(sizeof(struct Slist*)*m);
	scip(list, m, k, p);
	struct Slist *new = malloc(sizeof(struct Slist));
	new->k = k;
	new->next = malloc(sizeof(struct Slist *)*m);
	new->str = c;
	new->span = malloc(sizeof(long)*m);
	long i = 0;
	long r = (long) rand()*2;
	for (; (r%2==0) && (i < m);)
	{
		new->next[i] = p[i]->next[i];
		p[i]->next[i] = new;
		if (i != 0)
        {
			struct Slist * e = p[i];
			long count = 0;
			for (; e != new;)
			{
				e = e->next[0];
				count++;
			}
			long cp = p[i]->span[i];
			p[i]->span[i] = count;
			new->span[i] = cp-count+1;
			if (p[i]->next[i] == NULL) p[i]->span[i] = 0;
			if (new->next[i] == NULL) new->span[i] = 0;
		}
		else
		{
			p[i]->span[i] = 1;
			if (p[i]->next[i] == NULL) p[i]->span[i] = 0;
			new->span[i] = 1;
			if (new->next[i] == NULL) new->span[i] = 0;
		}

		r /= 2;
		i++;
	}
	int j = i;
	while (j < m)
	{
		new->span[j] = 0;
		new->next[j] = NULL;
		if (p[j]->next[j] != NULL) p[j]->span[j]++;
		j++;
	}
	free(p);
}
struct Slist * del(struct Slist * list, long m, long k)
{
	struct Slist ** p = malloc(sizeof(struct Slist*)*m);
	scip(list, m, k, p);
	long i = 0;
	struct Slist *res = suc(p[0]);
	for (; (i < m) && (p[i]->next[i] == res);)
	{
		p[i]->next[i] = res->next[i];
		if (p[i]->next[i] != NULL) p[i]->span[i] = p[i]->span[i] + res->span[i] - 1;
		else p[i]->span[i] = 0;
		i++;
	}
	long j = i;
	while (j < m)
	{
		if (p[j]->next[j] != NULL) p[j]->span[j]--;
		j++;
	}
	free(p);
	return res;
}
long rang(struct Slist * list, long m, long k)
{
	struct Slist* e = list;
	long counter = 0;
	long i = m - 1;
	for (; i>=0; i--)
	{
		while (e->next[i] != NULL)
		{
			if (e->next[i]->k <= k)
                if (e->str == NULL) counter += e->span[i] - 1;
				else counter += e->span[i];
			else if (e->k == k) return counter;
			else break;
			e = e->next[i];
		}
        if (e->next[i] == NULL && e->k == k) return counter;
	}
}

int main(int argc, char **argv)
{
	long n;
	scanf("%ld\n", &n);

	long m = (long) log2((double )n)+1;
	struct Slist *first = malloc(sizeof(struct Slist));
	first->k = -1000000000;
	first->next = malloc(sizeof(struct Slist *)*m);
	first->str = NULL;
	first->span = malloc(sizeof(long)*m);

	long j = 0;
	while (j < m)
	{
		first->next[j] = NULL;
		first->span[j] = 0;
		j++;
	}

	for (long i = 0; i < n; i++)
	{
		char s[500];
        fgets(s, 500, stdin);
        char *newline = strchr(s, '\n');
        if (newline) *newline = '\0';
		if (s[0]=='I')
		{

			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			char *c = malloc(sizeof(char)*100);
			strcpy(c, strtok(NULL, then));
			ins(first, m, k, c);
		}
		else if (s[0]=='L')
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			puts(look(first, m, k));
		}
		else if (s[0]=='D')
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			struct Slist *c = del(first, m, k);
			free(c->next);
			free(c->span);
			free(c->str);
			free(c);
		}
		else
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			printf("%ld\n", rang(first, m, k));
		}
	}
	struct Slist *e = first;
	while (e != NULL)
	{
		struct Slist * c = e;
		e = e->next[0];
		free(c->span);
		free(c->next);
		free(c->str);
		free(c);
	}
	return 0;
}
