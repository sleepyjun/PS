// https://www.acmicpc.net/problem/14500
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n,m;
bool range(int y, int x)
{
	return (0 <= x && x < m) && (0 <= y && y < n);
}
int map[501][501];
//y x
pii block[19][4] = {
	{{0,0}, {0,1}, {0,2}, {0,3}},
	{{0,0}, {1,0}, {2,0}, {3,0}},
	{{0,0}, {0,1}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {2,0}, {2,1}},
	{{0,0}, {1,0}, {0,1}, {0,2}},
	{{0,0}, {0,1}, {1,1}, {2,1}},
	{{0,0}, {0,1}, {0,2}, {-1,2}},
	{{0,0}, {1,0}, {1,1}, {2,1}},
	{{0,0}, {0,1}, {-1,1}, {-1,2}},
	{{0,0}, {1,0}, {0,1}, {-1,1}},
	{{0,0}, {0,1}, {1,1}, {1,2}},
	{{0,0}, {0,1}, {1,1}, {0,2}},
	{{0,0}, {0,1}, {0,2}, {-1,1}},
	{{0,0}, {1,0}, {1,1}, {2,0}},
	{{0,0}, {0,1}, {1,1}, {-1,1}},
	{{0,0}, {0,1}, {-1,1}, {-2,1}},
	{{0,0}, {0,1}, {0,2}, {1,2}},
	{{0,0}, {0,1}, {1,0}, {2,0}},
	{{0,0}, {1,0}, {1,1}, {1,2}}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; x < m; x++)
			cin >> map[y][x];
	}
	int res = 0;
	for(int type = 0; type < 19; ++type)
	{
		for(int y = 0; y < n; ++y)
		{
			for(int x = 0; x < m; ++x)
			{
				int sum = 0;
				for(int i = 0; i < 4; ++i)
				{
					int ny = block[type][i].first + y;
					int nx = block[type][i].second + x;
					if(range(ny,nx))
					{
						sum += map[ny][nx];
					}
					else
					{
						sum = 0; break;
					}
				}
				res = std::max(res,sum);
			}
		}
	}
	
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;