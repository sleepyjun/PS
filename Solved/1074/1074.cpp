#include <cstdio>
int cnt=0;
void func(int x, int y, int N)
{
	int n = (1 << N);
	int pivot = n*n/4;
	if(N == 1) 
	{
		if(x == 1 && y == 1) cnt = cnt+1;
		else if(x == 1 && y == 2) cnt = cnt+2;
		else if(x == 2 && y == 1) cnt = cnt+3;
		else cnt = cnt+4;
		
		return;
	}
	
	N--;
	if(x <= n/2 && y <= n/2)
	{
		func(x,y,N);
	}
	else if(x <= n/2 && y <= n)
	{
		cnt += pivot;
		func(x,y-n/2,N);
	}
	else if(x <= n && y <= n/2)
	{
		cnt += pivot*2;
		func(x-n/2,y,N);
	}
	else
	{
		cnt += pivot*3;
		func(x-n/2,y-n/2,N);
	}
}
int main()
{
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	r++; c++;
	func(r,c,N);
	printf("%d\n",cnt-1);
}