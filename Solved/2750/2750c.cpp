#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N,temp;
	int * arr;
	int i, j,k;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);

	for (i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	for (i = 0; i < N - 1; ++i)
	{
		k = i;//N번째 항목을 지정한다
		for (j = i+1; j < N; ++j)//i번째 아래는 정렬되있으니 무시해도됨
			if (arr[k] > arr[j])
				k = j;//그리고 작은 항목을 찾아나선다.
		temp = arr[i];//N번째 항목과
		arr[i] = arr[k];//제일작은것이 위치하는것과
		arr[k] = temp;//바꾼다
	}

	for (i = 0; i < N; ++i)
		printf("%d\n", arr[i]);
}