#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

struct Elem {
	struct Elem *next;
	char *word;
};

struct Elem *bsort(struct Elem *list)
{
	if (list == NULL) return list;
	struct Elem *alist = list;
	for (; 'a' == 'a';)
	{
		struct Elem *palist = alist;
		long i = 0;
		for (; NULL != palist->next;)
		{
			if (strlen(palist->next->word) < strlen(palist->word))
			{
			    char *c = palist->word;
				palist->word = palist->next->word;
				i++;
				palist->next->word = c;
			}
			palist = palist->next;
		}
		if (i == 0) return list;
	}
}

int main(int argc, char **argv)
{
	char del[1001] = " ", str[1001];
	fgets(str, 1001, stdin);
	str[strlen(str) - 1] = '\0';
	char *word = strtok(str, del);

	struct Elem *pl = NULL, *fl;
	for (; word != NULL;)
	{
		struct Elem *list = malloc(sizeof(struct Elem));
		list->word = word;

		if (pl == NULL) fl = list;
		else pl->next = list;

		word = strtok(NULL, del);
		pl = list;
	}

	if (!(NULL == pl)) pl->next = NULL;

	struct Elem *list = bsort(fl);
	for (; NULL != list;)
	{
		struct Elem *c = list;
		printf("%s\n", list->word);
		list = list->next;
		free(c);
	}
	return 0;
}
