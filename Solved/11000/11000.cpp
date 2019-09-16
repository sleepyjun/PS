#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int start;
	int end;
}time;

int compare(const void *a, const void *b)
{
	time *x = (time*)a;
	time *y = (time*)b;

	if (x->start > y->start)
		return 1;
	else if (x->start < y->start)
		return -1;
	else
		return (x->end - y->end);
}

int main()
{
	time *T;
	int N;
	int i, j;
	int cnt = 0;
	int *room;
	scanf("%d", &N);
	T = (time*)malloc(sizeof(time)*N);
	room = (int*)calloc(N,sizeof(int));

	for (i = 0; i < N; ++i)
		scanf("%d %d", &T[i].start, &T[i].end);
	qsort(T, N, sizeof(time), compare);
	
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (room[j] <= T[i].start)
			{
				room[j] = T[i].end;
				if (cnt < j)
					cnt = j;
				break;
			}
		}
	}
	printf("%d", cnt+1);
}