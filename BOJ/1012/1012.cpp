#include <iostream>
#include <algorithm>
#include <queue>
using std::cin; using std::cout;

bool map[51][51];
bool visited[51][51];

const int move[4][2] =
{ {-1,0}, {1,0}, {0,-1}, {0,1} };

int cnt;
int m,n;//x y

void func(int y, int x)
{
	std::queue<std::pair<int ,int > > q;
	visited[y][x] = true;
	q.push(std::make_pair(x, y));
	
	while(!q.empty())
	{
		std::pair<int, int> curr = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i)
		{
			int nx = curr.first + move[i][0];
			int ny = curr.second + move[i][1];
			if(nx < 0 || nx > m-1 || ny < 0 || ny > n-1) 
				continue;
			if(visited[ny][nx] == false)
			{
				visited[ny][nx] = true;
				if(map[ny][nx] == true)
					q.push(std::make_pair(nx, ny));
			}
		}
	}
	cnt++;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(&map[0][0], &map[50][50], false);
		std::fill(&visited[0][0], &visited[50][50], false);
		cin >> m >> n;
		
		int k; cin >> k;
		
		std::queue<std::pair<int, int> > q;
		for(int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = true;
		}
		
		cnt = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(map[i][j] == true && visited[i][j] == false)
					func(i, j);
		
		cout << cnt << '\n';
	}
}