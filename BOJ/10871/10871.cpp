#include<stdio.h>

int main()
{
	int arr[10001];
	int ar[10001];
	int i;
	int x;
	int n;
	int cnt=0;

	scanf("%d %d", &n,&x);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (x > arr[i])
		{
			ar[cnt] = arr[i];
			++cnt;
		}
	}
	for (i = 0; i < cnt; ++i)
	{
		printf("%d ", ar[i]);
	}
}