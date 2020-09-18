#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

char building[31][31][31];
bool visited[31][31][31];
//floor y x
std::tuple<int, int, int> start;
std::tuple<int, int, int> end;

int dir[6][3] = {
	{1,0,0},
	{-1,0,0},
	{0,1,0},
	{0,0,1},
	{0,-1,0},
	{0,0,-1}
};

void solve()
{
	std::queue<std::tuple<int, int, int> > q;
	bool flag = true;
	int cnt = 0;
	
	q.push(start);
	while(flag && !q.empty())
	{
		int qSize = q.size();
		for(int i = 0; i < qSize; ++i)
		{
			auto curr = q.front(); q.pop();
			
			if(curr == end)
			{
				flag = false;
				break;
			}
			for(int j = 0; j < 6; ++j)
			{
				int nf = std::get<0>(curr) + dir[j][0];
				int ny = std::get<1>(curr) + dir[j][1];
				int nx = std::get<2>(curr) + dir[j][2];
				
				if(building[nf][ny][nx] == '#') continue;
				if(visited[nf][ny][nx] == true) continue;
				visited[nf][ny][nx] = true;
				q.push(std::make_tuple(nf,ny,nx));
			}
		}
		cnt++;
	}
	
	if(flag == true)
		cout << "Trapped!";
	else
		cout << "Escaped in " << cnt-1 << " minute(s).";
	cout << '\n';
	
	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		std::fill(&building[0][0][0],&building[30][30][31],'#');
		std::fill(&visited[0][0][0],&visited[30][30][31],false);
		
		int l,r,c;
		cin >> l >> r >> c;
		if(l == 0) return 0;
		
		for(int i = 1; i <= l; ++i)
			for(int j = 1; j <= r; ++j)
				for(int k = 1; k <= c; ++k)
				{
					cin >> building[i][j][k];
					if(building[i][j][k] == 'S')
						start = std::make_tuple(i,j,k);
					else if(building[i][j][k] == 'E')
						end = std::make_tuple(i,j,k);
				}
		
		solve();
	}
}