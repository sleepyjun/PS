#include<cstdio>
using namespace std;

int arr[65][65];

void divide(int x, int y, int n)
{
	int flag0 = 1;
	int flag1 = 1;

	for(int i = 1; i <= n ; ++i)
		for(int j = 1; j <= n; ++j)
		{	
			if(arr[x+i][y+j] != 0) flag0 = 0;
			if(arr[x+i][y+j] != 1) flag1 = 0;
		}	
	n /= 2;
	if(flag0 == flag1)
	{
		printf("(");
		divide(x, y, n);
		divide(x, y+n, n);
		divide(x+n, y, n);
		divide(x+n, y+n, n);
		printf(")");
	}
	else if (flag0) printf("0");
	else printf("1");

}

int main()
{	
	int n; scanf("%d",&n);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%1d",&arr[i][j]);
	
	//cout << '(';
	divide(0, 0, n);
	//cout << ')';
}