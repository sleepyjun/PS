#include <cstdio>

unsigned long long arr[101];
int main()
{
	int t;
	int n;
	scanf("%d", &t);
	
	arr[1] = arr[2] = arr[3] = 1;
	for(int i = 4; i <= 100; ++i)
		arr[i] = arr[i-3] + arr[i-2];
	while(t--)
	{
		scanf("%d", &n);
		printf("%llu\n", arr[n]);
	}
}