// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n,m,res=INF;
int map[51][51];
bool visited[14];
std::vector<pii> home;
std::vector<pii> chicken;

void func(int cnt, int chickenIdx)
{
    if(cnt == m)
    {
        int ans = 0;
        for(auto homeCoord : home)
        {
            int temp = 999;
            for(int i = 0; i < chicken.size(); ++i)
            {
                if(visited[i] == true)
                {
                    temp = std::min(temp, 
                        std::abs(homeCoord.first - chicken[i].first) + std::abs(homeCoord.second - chicken[i].second));
                }
            }
            ans += temp;
        }
        res = std::min(res, ans);
        return;
    }
    for(int i = chickenIdx; i < chicken.size(); ++i)
    {
        visited[i] = true;
        func(cnt+1, i+1);
        visited[i] = false;
    }
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
    for(int y = 1; y <= n; ++y)
    {
        for(int x = 1; x <= n; ++x)
        {
            cin >> map[y][x];
            if(map[y][x] == 1)
                home.push_back({y,x});
            else if(map[y][x] == 2)
                chicken.push_back({y,x});
        }
    }
    func(0,0);
    cout << res <<'\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;
