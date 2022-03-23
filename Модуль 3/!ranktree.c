#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <malloc.h>

struct Bstree {
	char *str;
	long k, count;
	struct Bstree *parent, *left, *right;
};
struct Bstree *mini(struct Bstree *tree)
{
	struct Bstree *res;
	if (NULL != tree)
	{
		res = tree;
		while (!(NULL == res->left))
            res = res->left;
	}
	else
        res = NULL;

	return res;
}
struct Bstree *suc(struct Bstree *p)
{
	struct Bstree *res;
	if ((NULL == p->right))
	{
		res = p->parent;
		while (!((res->right != p) ||(NULL == res)))
		{
			p = res;
			res = res->parent;
		}
	}
	else
        res = mini(p->right);

	return res;
}
struct Bstree *des(struct Bstree *tree, long k)
{
	struct Bstree *p = tree;
	while (!(p->k == k || (p == NULL)))
		if (k >= p->k)
            p = p->right;
        else
			p = p->left;

	return p;
}
char *look(struct Bstree *tree, long k)
{
	struct Bstree *p = des(tree, k);
	return p->str;
}

struct Bstree *allpeaks[100001];
long allc = 0;

struct Bstree *ins(struct Bstree *tree, long k, char *str)
{
	struct Bstree *new = malloc(sizeof(struct Bstree));
	allpeaks[allc] = new;
	allc++;
	new->count = 0;
	new->right = NULL;
	new->left = NULL;
	new->parent = NULL;
	new->str = str;
	new->k = k;

	if (NULL == tree)
        tree = new;
	else
	{
		struct Bstree *p = tree;
		while ('c' == 'c')
			if (k >= p->k)
			{
				if (!(NULL == p->right))
				{
				    p->count++;
					p->right = new;
					new->parent = p;
					break;
				}
				p->count++;
				p = p->right;
			}
			else
			{
				if (!(NULL != p->left))
				{
				    p->count++;
					p->left = new;
					new->parent = p;
					break;
				}
				p->count++;
				p = p->left;
			}
	}
	return tree;
}
struct Bstree *rpn(struct Bstree *tree, struct Bstree* x, struct Bstree *y)
{
	if (tree == x)
	{
		tree = y;
		if (!(NULL == y))
            y->parent = NULL;
	}
	else
	{
		struct Bstree *p = x->parent;
		if (y != NULL)
		{
			y->parent = p;
			p->count = y->count + p->count - x->count;
			struct Bstree *e = p->parent;
			while (e != NULL)
			{
				e->count = e->count - x->count + y->count;
				e = e->parent;
			}
		}
		else
		{
			p->count = 0 - 1 - x->count + p->count;
			struct Bstree *e = p->parent;
			while (!(NULL == e))
			{
				e->count = e->count - x->count - 1;
				e = e->parent;
			}
		}
		if (x != p->left)
            p->right = y;
		else
            p->left = y;
	}
	return tree;
}
char *rang(struct Bstree *tree, long x)
{
	struct Bstree *ptree = tree;
	while ('y' == 'y')
	{
		long pc;
		if (NULL == ptree->left) pc = -1;
		else pc = ptree->left->count;

		if (pc+1 == x)
            return ptree->str;
		else if (x > pc)
		{
			ptree = ptree->right;
			x -= pc+2;
		}
		else
            ptree = ptree->left;
	}
}

struct Bstree *del(struct Bstree* tree, long k)
{
	struct Bstree *x = des(tree, k);
	if (!(NULL != x->right || NULL != x->left))
        tree = rpn(tree, x, NULL);
	else if (NULL == x->right)
        tree = rpn(tree, x, x->left);
	else if (NULL == x->left)
        tree = rpn(tree, x, x->right);
	else
	{
		struct Bstree *y = suc(x);
		tree = rpn(tree, y, y->right);
		x->left->parent = y;
		y->left = x->left;
		if (!(NULL == x->right))
			x->right->parent = y;
        y->count = x->count;
		y->right = x->right;
		tree = rpn(tree, x, y);
	}
	return tree;
}
int main(int argc, char **argv)
{
	long n;
	scanf("%ld", &n);

	struct Bstree *tree = NULL;
	for (long i=0; i<n; i++)
	{
		char s[100];
		fgets(s, 100, stdin);
		s[strlen(s)] = '\0';
		if (s[0] == 'I')
		{
			char then[100] = " ";
			strtok(s, then);
			char *c = malloc(sizeof(char)*100);
			long k = strtol(strtok(NULL, then), NULL, 10);
			strcpy(c, strtok(NULL, then));
			tree = ins(tree, k, c);
		}
		else if (s[0] == 'D')
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			tree = del(tree, k);
		}
		else if (s[0] == 'L')
		{
			char then[100] = " ";
			strtok(s, then);
			long k = strtol(strtok(NULL, then), NULL, 10);
			puts(look(tree, k));
		}
		else
		{
			char then[100] = " ";
			strtok(s, then);
			long x = strtol(strtok(NULL, then), NULL, 10);
			puts(rang(tree, x));
		}
	}
	for (long i=0; i<allc; i++)
	{
		free(allpeaks[i]->str);
		free(allpeaks[i]);
	}
	return 0;
}
