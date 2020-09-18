/*
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중 앙 값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최 빈 값 : N개의 수들 중 가장 많이 나타나는 값:
범    위 : N개의 수들 중 최대값과 최소값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1≤N≤500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절대값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.

예제 입력  복사
5
1
3
8
-2
2
예제 출력  복사
2
2
1
10
*/
#include<stdio.h>
#include<stdlib.h>

int compare(const void*a, const void*b)
{
	int*x = (int*)a;
	int*y = (int*)b;
	return *x - *y;
}

int main()
{
	int N;
	int *arr, cnt[8001] = { 0 };
	double sum = 0;
	int max = 0;
	int i,j=0;
	int mid,tmp[8002],sw;

	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int)*N);
	

	for (i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		cnt[arr[i]+4000]++;
	}
	printf("%0.lf\n", sum / N);// 산술평균
	
		
	for (i = 0; i < 8002; ++i)
	{
		if (max < cnt[i])
		{
			j = 0;
			sw = 1;
			max = cnt[i];
			tmp[j++] = i-4000;
		}
		else if (max == cnt[i])
		{
			sw = 0;
			tmp[j++] = i - 4000;
		}
	
	}

	qsort(arr, N, sizeof(int), compare);//정렬

	mid = (N + 1) / 2 - 1;
	printf("%d\n", arr[mid]);

	
	printf("%d\n", sw?tmp[0]:tmp[1]);
	printf("%d\n", arr[N-1] - arr[0]);
	
	
	free(arr),arr = NULL;
}