#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int arr[1000][1000];
//idx will be start 1
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int find; cin >> find;

	int x = 1;
	int y = 0;
	int len = n;
	int cnt = n*n;
	int flag = 1;
	int ansX, ansY;
	
	while(len!=0)
	{//arr[y][x] => (y,x)
		for(int i = 1; i <= len; ++i)
		{
			y += flag;
			arr[y][x] = cnt;
			cnt--;
		}
		len--;
		for(int i = 1; i <= len; ++i)
		{
			x += flag;
			arr[y][x] = cnt;
			cnt--;
		}
		flag *= -1;
	}
	
	for(y = 1; y <= n; ++y)
	{
		for(x = 1; x <= n; ++x)
		{
			cout << arr[y][x] << ' ';
			if(arr[y][x] == find)
			{
				ansX = x;
				ansY = y;
			}
		}
		cout << '\n';
	}
	cout << ansY << ' ' << ansX << '\n';
}