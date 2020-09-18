#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

const int dir[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
int mainBoard[8][8];
int subBoard[8][8];
bool visited[8][8];
int n, m; 
void init() 
{
	for(int y = 0; y < n; ++y)
		for(int x = 0; x < m; ++x)
			subBoard[y][x] = mainBoard[y][x];
	std::fill(&visited[0][0], &visited[7][8], false);
}

int bfs(const std::vector<int>& virus)
{
	std::queue<pii> q;
	for(const auto yx : virus)
	{
		q.push({yx/10, yx%10});
		visited[yx/10][yx%10] = true;
	}
	
	while(!q.empty()) 
	{
		auto curr = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) 
		{
			int ny = curr.first + dir[i][0];
			int nx = curr.second + dir[i][1];
			
			if(ny < 0 || ny > n-1 || nx < 0 || nx > m-1) continue;
			if(subBoard[ny][nx] == 1) continue;
			if(visited[ny][nx] == true) continue;
			visited[ny][nx] = true;
			subBoard[ny][nx] = 2;
			q.push({ny,nx});
		}
	}
	
	int cnt = 0;
	for(int y = 0; y < n; ++y)
		for(int x = 0; x < m; ++x)
			if(subBoard[y][x] == 0) cnt++;
	
	return cnt;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	std::vector<int> empty, virus;
	empty.reserve(64); virus.reserve(10);
	
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < m; ++x)
		{
			int e; cin >> e;
			mainBoard[y][x] = e;
			if(e==0) empty.push_back(y*10+x);
			else if(e==2) virus.push_back(y*10+x);
		}
	}
	
	int emptyCnt = empty.size();
	int res = -1;
	init();
	for(int i = 0; i < emptyCnt; ++i)
	{
		for(int j = i+1; j < emptyCnt; ++j)
		{
			for(int k = j+1; k < emptyCnt; ++k)
			{
				subBoard[empty[i]/10][empty[i]%10] = 1;
				subBoard[empty[j]/10][empty[j]%10] = 1;
				subBoard[empty[k]/10][empty[k]%10] = 1;
				res = std::max(res,bfs(virus));
				init();
			}
		}
	}
	
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;