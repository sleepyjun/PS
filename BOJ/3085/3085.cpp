#include<stdio.h>
#include<stdlib.h>

#define max(a,b) (((a)>(b))?(a):(b))

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int ans1(int N, char arr[][51], int j/*바뀐부분*/)
{
	int i;
	int cnt = 0;
	int tmp = 1;
	for (i = 0; i < N - 1; ++i)
	{
		
		if (arr[i][j] != arr[i + 1][j])
		{
			cnt = max(tmp, cnt);
			tmp = 1;
		}
		else
			++tmp;
	}
	cnt = max(cnt, tmp);
	return cnt;
}

int ans2(int N, char arr[][51], int j/*바뀐부분*/)
{
	int i;
	int cnt = 0;
	int tmp = 1;
	for (i = 0; i < N - 1; ++i)
	{
		if (arr[j][i] != arr[j][i + 1])
		{
			cnt = max(tmp, cnt);
			tmp = 1;
		}
		else 
			++tmp;
	}
	cnt = max(cnt, tmp);
	return cnt;
}

int main()
{
	int N, res = 0;
	char arr[51][51];
	int i, j;
	scanf("%d", &N);
	getchar();

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			scanf(" %c", &arr[i][j]);
		}
	}

	//가로만 교환
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
		{
			swap(&arr[i][j], &arr[i][j + 1]);
			res = max(ans1(N, arr, j), res);
			res = max(ans1(N, arr, j + 1), res);
			res = max(ans2(N, arr, i), res);
			swap(&arr[i][j], &arr[i][j + 1]);
		
	//세로만 교환
	
			swap(&arr[j][i], &arr[j + 1][i]);
			res = max(ans2(N, arr, j), res);
			res = max(ans2(N, arr, j + 1), res);
			res = max(ans1(N, arr, i), res);
			swap(&arr[j][i], &arr[j + 1][i]);
		}

	printf("%d", res);
}