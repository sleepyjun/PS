// https://www.acmicpc.net/problem/17406
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <tuple>
#include <numeric>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};

int n,m,k;
int src[101][101];
int arr[101][101];

int find()
{
	int ret = INF;
	for(int y = 1; y <= n; ++y)
	{
		int sum = 0;
		for(int x = 1; x <= m; ++x)
			sum += arr[y][x];
		ret = std::min(ret, sum);
	}

	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k;

	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= m; ++x)
			cin >> src[y][x];

	std::vector<int> v(k);
	std::vector<std::tuple<int, int, int> > cond;
	std::iota(v.begin(), v.end(), 0);


	while(k--)
	{
		int r,c,s; cin >> r >> c >> s;
		cond.push_back({r,c,s});
	}

	int res = INF;
	do {
		std::copy(&src[0][0], &src[100][101], &arr[0][0]);
		for(int idx: v)
		{	
			int r,c,s;
			std::tie(r,c,s) = cond[idx];
			
			for(int i = 1; i <= s; ++i)
			{
				//start from left lower
				int cy = r+i;
				int cx = c-i;
				//limit
				int ly = r+i;
				int lx = c+i;
				//run;
				int idx = 0;
				int temp = arr[cy][cx];
				while(1)
				{
					int ny = cy+DIR[idx][0];
					int nx = cx+DIR[idx][1];

					if(ny < r-i || nx < c-i || ny > ly || nx > lx)
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
		res = std::min(res,find());
	} while(std::next_permutation(v.begin(), v.end()));
	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp