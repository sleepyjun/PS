/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1<=N<=1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다.
이 수는 절대값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

예제 입력
5
5
2
3
4
1

예제 출력
1
2
3
4
5
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, temp;
	int * arr;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 1; j < N - i; ++j)
			if (arr[j-1] > arr[j])
			{
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
	}
	for (int i = 0; i < N; ++i)
		printf("%d\n", arr[i]);
}