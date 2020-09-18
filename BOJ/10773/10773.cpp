#include <cstdio>
#include <algorithm>
int arr[100000];
int main()
{
	unsigned long long res = 0;
	int pos = 0;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		
		scanf("%d", &n);
		if(n == 0)
			pos--;
		else
			arr[pos++] = n;
	}		
	for(int i = 0; i < pos; ++i)
			res += arr[i];
	printf("%llu\n", res);
}