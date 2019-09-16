#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int start;
	int end;
}time;
int compare(const void *a, const void *b)
{
	time* x = (time*)a;
	time* y = (time*)b;
	if (x->end > y->end) return 1;
	else if (x->end < y->end) return -1;
	else
	{
		return (x->start - y->start);
	}
}


int main()
{
	int i, N;
	int key = 0;
	int cnt = 1;
	time *arr;
	scanf("%d", &N);
	arr = (time *)malloc(sizeof(time)*N);

	for (i = 0; i < N; ++i)
	{
		scanf("%d %d", &(arr + i)->start, &(arr + i)->end);
	}
	qsort(arr,N,sizeof(time),compare);
	for (i = 1; i < N; ++i)
	{
		if (arr[key].end <= arr[i].start)
		{
			cnt++;
			key = i;
		}
	}
	
	printf("%d", cnt);
}