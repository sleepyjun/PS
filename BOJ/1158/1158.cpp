#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int N;
	struct _node *next;
}node;

typedef node* nptr;

nptr firstnode = NULL;
nptr lastnode = NULL;

void del(int, int);
void insert(int);

int main()
{
	int N, M;
	nptr nodes;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++i)
		insert(i);
	
	del(N, M);
}

void insert(int N)
{
	nptr new_node = (nptr)malloc(sizeof(node));
	new_node->N = N;
	new_node->next = NULL;

	if (firstnode == NULL)
	{
		firstnode = new_node;
		lastnode = new_node;
		lastnode->next = firstnode;
	}
	else
	{
		lastnode->next = new_node;
		lastnode = new_node;
		lastnode->next = firstnode;
	}
}
void del(int N,int M)
{
	int i,j;
	nptr temp = firstnode;
	nptr before = lastnode;
	putchar('<');
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < M-1; ++j)
		{
			temp = temp->next;
			before = before->next;
		}
		printf("%d", temp->N);
		before->next = temp->next;
		free(temp);
		temp = before->next;

		if (i != N - 1)
		{
			printf(", ");
		}
	}
	putchar('>');
}