#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int n; 
int arr[101][101];
int weight[101][101];
int cnt[101][101];

int calc(int y = 1, int x = 1, int depth = 1)
{
	if(y > depth || x > depth) return 0;
	if(depth == n+1) return arr[y][x];
	
	int& ret = weight[y][x];
	if(ret != -1) return ret;
	
	ret = std::max(calc(y+1,x,depth+1), calc(y+1,x+1,depth+1))+arr[y][x];
	return ret;
}
int run(int y = 1, int x = 1, int depth = 1)
{
	if(y > depth || x > depth) return 0;	
	if(depth == n+1) return 1;
	
	int& ret = cnt[y][x];
	if(ret != -1) return ret;
	ret = 0;
	if(weight[y+1][x] >= weight[y+1][x+1])
		ret += run(y+1,x,depth+1);
	if(weight[y+1][x] <= weight[y+1][x+1])
		ret += run(y+1,x+1,depth+1);

	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(&arr[0][0], &arr[100][100], 0);
		std::fill(&weight[0][0], &weight[100][100], -1);
		std::fill(&cnt[0][0], &cnt[100][100], -1);
		
		cin >> n;
		for(int i = 1; i <= n ; ++i)
			for(int j = 1; j <= i; ++j)
				cin >> arr[i][j];
		calc();
		
		cout << run()/2 << '\n';
	}
}