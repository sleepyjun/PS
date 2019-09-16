#include <iostream>
#include <algorithm>

int n;
int posible[100][100];
int arr[100][100];
int func(int x, int y)
{
	if(x >= n || y >= n) return 0;
	if(x == n-1 && y == n-1) return 1;
	
	int& ret = posible[y][x];
	if(ret != -1) return ret;
	int jumpSize = arr[y][x];
	return ret = func(x+jumpSize , y) || func(x, y+jumpSize);
	
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int t; std::cin >> t;
	while(t--)
	{
		std::cin >> n;
		std::fill(&posible[0][0], &posible[99][99], -1);
		std::fill(&arr[0][0], &arr[99][99], -1);
		for(int i = 0 ; i < n; ++i)
			for(int j = 0; j < n; ++j)
				std::cin >> arr[i][j];
		
		if(func(0,0))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
}