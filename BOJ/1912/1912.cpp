#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int arr[100010];
int hap[100010];

int main()
{	
	int N;
	int ans;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	
	hap[0] = arr[0];
	ans = hap[0];
	for (int i = 1; i < N; ++i)
	{
		hap[i] = MAX(hap[i-1] + arr[i], arr[i]);
		ans = MAX(ans, hap[i]);
	}
	printf("%d", ans);
	
}