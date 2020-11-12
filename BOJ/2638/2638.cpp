// https://www.acmicpc.net/problem/2638
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

enum {EMPTY, CHEESE, IN};
bool visited[101][101];
int map[101][101];
int X,Y;
int cnt;

void test()
{
    for(int y = 1; y <= Y; ++y)
    {
        for(int x = 1; x <= X; ++x)
        {
            cout << map[y][x] << ' ';
        }
        cout << '\n';
    }
}
bool position(int y, int x)
{
    if(y < 1 || x < 1 || y > Y || x > X) return false;
    if(visited[y][x] == true) return false;
    if(map[y][x] == CHEESE) return false;
    return true;
}
void air()
{
    for(int y = 1; y <= Y; ++y)
        for(int x = 1; x <= X; ++x)
            if(map[y][x] == IN) map[y][x] = EMPTY;
    std::fill(&visited[0][0], &visited[100][101], false);
    
    std::queue<pii> q;
    q.push({1,1}); visited[1][1] = true;
    while(!q.empty())
    {
        auto& p = q.front(); q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int ny = p.first+DIR[i][0];
            int nx = p.second+DIR[i][1];
            if(false == position(ny, nx)) continue;
            visited[ny][nx] = true;
            q.push({ny,nx});
        }
    }
    for(int y = 1; y <= Y; ++y)
        for(int x = 1; x <= X; ++x)
            if(visited[y][x] == false && map[y][x] == EMPTY)
                map[y][x] = IN;
}
bool melt(int y, int x)
{
    int out = 0;
    for(int i = 0; i < 4; ++i)
    {
        int ny = y+DIR[i][0];
        int nx = x+DIR[i][1];
        if(map[ny][nx] == EMPTY) out++;
    }
    return out >= 2;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int res = 0;
    cin >> Y >> X;  
    for(int y = 1; y <= Y; ++y)
    {
        for(int x = 1; x <= X; ++x)
        {
            cin >> map[y][x];
            if(map[y][x] == CHEESE) cnt++;
        }
    }
    
    while(1)
    {
        std::queue<pii> q;
        if(cnt <= 0) break;
        air();
        for(int y = 1; y <= Y; ++y)
        {
            for(int x = 1; x <= X; ++x)
            {
                if(map[y][x] == CHEESE)
                {
                    if(true == melt(y,x))
                    {
                        q.push({y,x});
                        cnt -= 1;
                    }
                }
            }
        }
        while(!q.empty())
        {
            auto& p = q.front(); q.pop();
            map[p.first][p.second] = EMPTY;
        }
        res++;
    }

    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp