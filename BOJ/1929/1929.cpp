#include<stdio.h>
#include<stdlib.h>

int arr[1000001] = { 0 };

int main()
{
	int M, N;	
	int start;
	int check;
	scanf("%d %d", &M, &N);

	
	for (start = 2; start <= N; ++start)
		arr[start] = start;

	for (start = 2; start*start <= N; ++start)
	{
		if (arr[start] == 0) continue;

		for (check = start*start;  check <= N; check = check + start)
		{
			arr[check] = 0;
		}
	}

	for (start = M; start <= N; ++start)
		if (arr[start])
			printf("%d\n", arr[start]);
	

}