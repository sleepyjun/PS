// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int map[501][501];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int Y,X,B; cin >> Y >> X >> B;
    int res = INF, ans=0;
    int min = INF, max = -1;
    // vertical , horizon, inven
    for(int i = 1; i <= Y; ++i)
    {
        for(int j = 1; j <= X; ++j)
        {
            cin >> map[i][j];
            min = std::min(min, map[i][j]);
            max = std::max(max, map[i][j]);
        }
    }
    for(int floor = min; floor <= max; ++floor)
    {
        int inven = B;
        int time = 0;
        for(int i = 1; i <= Y; ++i)//del higher component
        {
            for(int j = 1; j <= X; ++j)
            {
                if(map[i][j] > floor) 
                {
                    time += (map[i][j]-floor)*2; //del
                    inven += (map[i][j]-floor);
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= Y; ++i)//add for lower component
        {
            for(int j = 1; j <= X; ++j)
            {
                if(map[i][j] < floor) 
                    cnt += (floor-map[i][j]);
            }
        }
        if(cnt <= inven)
        {
            time += cnt;
            if(res >= time)
            {
                res = time;
                ans = floor;
            }
        }
    }

    cout << res << ' ' << ans << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;