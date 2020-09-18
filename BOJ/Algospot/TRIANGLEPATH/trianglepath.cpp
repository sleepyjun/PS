#include <iostream>
#include <algorithm>

int sum[100][100];
int arr[100][100];
int n; 

int func(int x = 0, int y = 0, int depth = 0)
{
	if(x > depth || y > depth) return 0;
	if(depth == n-1) return arr[y][x];
	
	
	int& ret = sum[y][x];
	if(ret != -1) return ret;
	ret = std::max(func(x, y+1, depth+1), 
				   func(x+1, y+1, depth+1)) + arr[y][x];
	
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	int t; std::cin >> t;
	while(t--)
	{
std::cin >> n;
		std::fill(&sum[0][0], &sum[99][99], -1);
		std::fill(&arr[0][0], &arr[99][99], 0);
		
		for(int i = 0; i < n; ++i)
			for(int j = 0; j <= i; ++j)
				std::cin >> arr[i][j];
		
		std::cout << func() << '\n';
	}
}