// https://www.acmicpc.net/problem/17144
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

enum {HORIZON, VERTICAL, DIAGONAL};
const int DIR[3][2] =
{
    {0,1},
    {1,0},
    {1,1}
};

int map[20][20];
bool visited[20][20];
int n; 
bool position(int y, int x, int next)
{
    if(next == DIAGONAL)
    {
        for(int i = 0; i < 3; ++i)
        {
            int ny = y+DIR[i][0];
            int nx = x+DIR[i][1];
            if(ny < 0 || ny > n || nx < 0 || nx > n) return false;
            if(map[ny][nx] == 1) return false;
        }
        return true;
    }
    int ny = y+DIR[next][0];
    int nx = x+DIR[next][1];
    if(ny < 0 || ny > n || nx < 0 || nx > n) return false;
    if(map[ny][nx] == 1) return false;
    else return true;
    
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
    int res = 0;
    std::queue<std::tuple<int, int, int> > q;
    q.push(std::make_tuple(1,2,HORIZON));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> map[i][j];
        }
    }

    while(!q.empty())
    {
        const auto &curr = q.front();
        int cy,cx,prev;
        std::set<pii> s;
        std::tie(cy,cx,prev) = curr;
        q.pop();
        if(cy == n && cx == n)
        {
            res++;
            continue;
        }
        for(int next = 0; next < 3; ++next)
        {
            if((next == HORIZON && prev == VERTICAL) ||
               (next == VERTICAL && prev == HORIZON)) continue;
            if(false == position(cy,cx,next)) continue;
            int ny = cy+DIR[next][0];
            int nx = cx+DIR[next][1];
            q.push(std::make_tuple(ny,nx,next));
        }
    }

    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp