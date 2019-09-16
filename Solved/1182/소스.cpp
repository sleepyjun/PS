#include<stdio.h>
#include<stdlib.h>
int cnt;
int N, S;
int arr[21];

void ans(int key, int sum)
{
	sum += arr[key];
	if (key == N)
		return;
	if (sum == S)
		cnt++;
	ans(key + 1, sum);
	ans(key + 1, sum - arr[key]);
}
int main()
{
	int i;

	scanf("%d %d", &N,&S);
	for (i = 0; i < N; ++i)
	{
		scanf("%d", (arr + i));
	}

	ans(0,0);
	printf("%d", cnt);
}