#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using std::cin; using std::cout;

typedef std::pair<int, std::pair<int, int>> wxy;
const int INF = 987654321;
const int move[4][2] = {
	{0,1}, {1,0}, {-1,0}, {0,-1}
};
int arr[126][126];
int dp[126][126];
int n;

int solve()
{
	std::priority_queue<wxy, std::vector<wxy>, std::greater<wxy> > pq;
	dp[0][0] = arr[0][0];
	pq.push({arr[0][0],{0, 0}});
	while(!pq.empty())
	{
		int cw = pq.top().first;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();
		if(dp[cy][cx] < cw) continue;
		for(int i = 0; i < 4; ++i)
		{
			int nx = cx+move[i][0];
			int ny = cy+move[i][1];
			if((nx < 0 || nx > n-1) || 
			   (ny < 0 || ny > n-1)) continue;
			int nw = cw+arr[ny][nx];
			if(dp[ny][nx] > nw)
			{
				dp[ny][nx] = nw;
				pq.push({nw,{nx,ny}});
			}
		}
	}
	
	return dp[n-1][n-1];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int idx = 1;
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		
		std::fill(&dp[0][0], &dp[125][125], INF);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				cin >> arr[i][j];
		}
		
		cout << "Problem " << idx++ << ": " << solve() << '\n';
	}
}