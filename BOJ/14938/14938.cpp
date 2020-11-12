// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = 1000000;

int map[101][101];
int item[101];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    std::fill(&map[0][0], &map[100][101], INF);
	int n,m,r; cin >> n >> m >> r;
    for(int i = 1; i <= n; ++i)
    {
        cin >> item[i];
        map[i][i] = 0;
    }
    for(int i  = 0; i < r; ++i)
    {
        int a,b,w; cin >> a >> b >> w;
        map[a][b] = w;
        map[b][a] = w;
    }

    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    int res = -1;
    for(int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(map[i][j] <= m)
            {
                sum += item[j];
            }
        }
        res = std::max(res, sum);
    }

    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp