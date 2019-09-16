#include <cstdio>

int arr[2188][2188];

int m1 = 0;
int _0 = 0;
int _1 = 0;
void divide(int x, int y, int n)
{
	int flagm1 = 1;
	int flag0 = 1;
	int flag1 = 1;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(arr[i+y][j+x] != -1) flagm1 = 0;
			if(arr[i+y][j+x] != 0) flag0 = 0;
			if(arr[i+y][j+x] != 1) flag1 = 0;
		}
	
	if(flagm1) m1++;
	else if(flag0) _0++;
	else if(flag1) _1++;
	else
	{
		n /= 3;
		divide(x, y, n);
		divide(x + n, y, n);
		divide(x + n*2, y, n);
		divide(x, y + n, n);
		divide(x + n, y + n, n);
		divide(x + n*2, y + n, n);
		divide(x, y + n*2, n);
		divide(x + n, y + n*2, n);
		divide(x + n*2, y + n*2, n);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &arr[i][j]);
	
	divide(0, 0, n);
	
	printf("%d\n%d\n%d\n", m1, _0, _1);
}