#include <iostream>
#include <algorithm>
#include <queue>
using std::cin; using std::cout;

typedef std::queue<std::pair<std::pair<int,int>, int> > qp;
typedef std::pair<std::pair<int, int>, int> pair;

char laby[1001][1001];
int visited[1001][1001][2];
int n,m; //n==y, m==x

const int move[4][2] = {
	{0,-1},{0,1},{-1,0},{1,0}
};//[0]x [1]y

int solve()
{
	qp q;//first xy second useBroken
	visited[1][1][1] = visited[1][1][0] = 1;
	q.push(std::make_pair(std::make_pair(1,1), 0));
	
	int level = 1;
	
	while(!q.empty())
	{
		level++;
		int qSize = q.size();
		for(int i = 0; i < qSize; ++i)
		{
			pair p = q.front(); q.pop();
			
			for(int j = 0; j < 4; ++j)
			{
				int nx = p.first.first + move[j][0];
				int ny = p.first.second + move[j][1];
				int broken = p.second;
				
				if((nx < 1 || nx > m) || (ny < 1 || ny > n)) continue;
				if(visited[ny][nx][broken] != 0) continue;
				
				if(laby[ny][nx] == '1' && broken == 0)
					broken = 1;
				else if(laby[ny][nx] == '1') continue;
				
				visited[ny][nx][broken] = level;
				q.push(std::make_pair(std::make_pair(nx,ny), broken));
			}
		}
		
	}

	if(visited[n][m][0]!=0 && visited[n][m][1]!=0)
		return std::min(visited[n][m][0],visited[n][m][1]);
	else if(visited[n][m][0]==0 && visited[n][m][1]!=0)
		return visited[n][m][1];
	else if(visited[n][m][0]!=0 && visited[n][m][1]==0)
		return visited[n][m][0];
	else return -1;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> laby[i][j];
	
	cout << solve() << '\n';
	
}