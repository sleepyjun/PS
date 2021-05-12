// https://www.acmicpc.net/problem/16926
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}
};
int arr[301][301];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m,r; cin >> n >> m >> r;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> arr[i][j];

	int t = n/2;
	for(int i = 1; i <= t; ++i)
	{
		int cy = i;
		int cx = i;

		int ly = n-i+1;
		int lx = m-i+1;

		int col = ly-cy+1;
		int row = lx-cx+1;

		int cnt = col*2 + row*2 - 4;
		if(cnt <= 0) continue;
		int iter = r%cnt;

		while(iter--)
		{
			int idx = 0;
			int temp = arr[cy][cx];
			while(1)
			{
				int ny = cy+DIR[idx][0];
				int nx = cx+DIR[idx][1];
				
				if(ny < i || nx < i || ny > ly || nx > lx)
				{
					idx++;
					if(idx == 4) break;
					continue;
				}

				int save = arr[ny][nx];
				arr[ny][nx] = temp;
				temp = save;
				cy = ny;
				cx = nx;
			}
		}
	}


	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}//g++ -o a -std=c++17 *.cpp