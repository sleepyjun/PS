#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using std::cin; using std::cout;

const int movement[8][2] = //x,y
{{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int len;
bool visited[401][401];

void bfs(int cx, int cy, const int ax, const int ay)
{
	if(cx == ax && cy == ay)
	{
		cout << 0 << '\n'; return;
	}
	
	std::queue<std::pair<int,int> > q;
	int depth = 0;
	bool flag = true;
	
	visited[cy][cx] = true;
	q.push(std::make_pair(cx, cy));
	
	while(!q.empty())
	{
		int qSize = q.size();
		for(int i = 0; i < qSize; ++i)
		{
			std::pair<int, int> curr = q.front();
			q.pop();
			for(int i = 0; i < 8 && flag; ++i)
			{
				int nx = curr.first + movement[i][0];
				int ny = curr.second + movement[i][1];
				if((nx < 0 || nx >= len) || (ny < 0 || ny >= len)) continue;

				if(visited[ny][nx] == false)
				{
					visited[ny][nx] = true;
					q.push(std::make_pair(nx, ny));
				}
				if(visited[ay][ax] == true) flag = false;
			}
		}
		depth++;
		if(!flag)
			break;
	}
	
	cout << depth << '\n';
	return;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(&visited[0][0], &visited[400][400], false);
		cin >> len;
		int cx, cy; cin >> cx >> cy;
		int ax, ay; cin >> ax >> ay;
		bfs(cx,cy,ax,ay);
	}
}