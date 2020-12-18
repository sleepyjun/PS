// https://www.acmicpc.net/problem/16946
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
int map[1001][1001];
bool visited[1001][1001];
std::set<pii> wall;
int y,x;

bool position(int cy, int cx)
{
    if(cy < 1 || cy > y || cx < 1 || cx > x) return false;
    if(visited[cy][cx] == true) return false;
    if(wall.find({cy,cx}) != wall.end()) return false;
    return true;
}
void bfs(int cy, int cx)
{
    int cnt = 1;
    std::queue<pii> q;
    
    q.push({cy,cx}); visited[cy][cx] = true;
    while(!q.empty())
    {
        const auto &curr = q.front();
        int cy = curr.first;
        int cx = curr.second;
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int ny = cy+DIR[i][0];
            int nx = cx+DIR[i][1];
            if(false == position(ny,nx)) continue;
            if(map[ny][nx] != 0)
                wall.insert({ny,nx});
            else 
            {
                cnt++;
                visited[ny][nx] = true;
                q.push({ny,nx});
            }
        }
    }

    for(const auto &w : wall)
    {
        int cy = w.first;
        int cx = w.second;
        map[cy][cx] += cnt;
    }
    wall.clear();
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> y >> x;
    for(int i = 1; i <= y; ++i)
    {
        for(int j = 1; j <= x; ++j)
        {
            char ch; cin >> ch;
            map[i][j] = ch-'0';
        }
    }

    for(int i = 1; i <= y; ++i)
    {
        for(int j = 1; j <= x; ++j)
        {
            if(map[i][j] == 0 && visited[i][j] == false)
            {
                bfs(i,j);
            }
        }
    }

    for(int i = 1; i <= y; ++i)
    {
        for(int j = 1; j <= x; ++j)
            cout << map[i][j] % 10;
        cout << '\n';
    }
}//g++ -o a -std=c++11 *.cpp