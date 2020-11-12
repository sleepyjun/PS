// https://www.acmicpc.net/problem/1865
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
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
int map[51][51];
std::vector<pii> airClean;

void diffusion(int y, int x)
{
    int temp[51][51];
    std::fill(&temp[0][0], &temp[50][51], 0);
    for(int _y = 1; _y <= y; ++_y)
    {
        for(int _x = 1; _x <= x; ++_x)
        {
            if(map[_y][_x] != 0)
            {
                int diffuse = map[_y][_x]/5;
                int cnt = 0;
                for(int i = 0; diffuse && i < 4; ++i)
                {
                    int ny = _y+DIR[i][0];
                    int nx = _x+DIR[i][1];
                    if(ny < 1 || ny > y ||
                       nx < 1 || nx > x) continue;
                    if(map[ny][nx] == -1) continue;
                    cnt++;
                    temp[ny][nx] += diffuse;
                }
                map[_y][_x] -= diffuse*cnt;
            }
        }
    }
    
    for(int _y = 1; _y <= y; ++_y)
    {
        for(int _x = 1; _x <= x; ++_x)
        {
            map[_y][_x] += temp[_y][_x];
        }
    }
    for(const auto &cleaner : airClean)
        map[cleaner.first][cleaner.second] = -1;
}
int clean(int y, int x)
{
    int temp[51][51];
    std::fill(&temp[0][0], &temp[50][51], 0);

    int ay = airClean.front().first;
    for(int _y = 1; _y <= ay; ++_y)
    {
        for(int _x = 1; _x <= x; ++_x)
        {
            if(map[_y][_x] == -1) continue;

            if(_y == ay && _x != x)
                temp[_y][_x+1] = map[_y][_x];
            else if(_x == x && _y != 1)
                temp[_y-1][_x] = map[_y][_x];
            else if(_y == 1 && _x != 1)
                temp[_y][_x-1] = map[_y][_x];
            else if(_x == 1 && _y != ay)
                temp[_y+1][_x] = map[_y][_x];
            else temp[_y][_x] = map[_y][_x];
        }
    }

    ay = airClean.back().first;
    for(int _y = ay; _y <= y; ++_y)
    {
        for(int _x = 1; _x <= x; ++_x)
        {
            if(map[_y][_x] == -1) continue;

            if(_y == ay && _x != x)
                temp[_y][_x+1] = map[_y][_x];
            else if(_x == x && _y != y)
                temp[_y+1][_x] = map[_y][_x];
            else if(_y == y && _x != 1)
                temp[_y][_x-1] = map[_y][_x];
            else if(_x == 1 && _y != ay)
                temp[_y-1][_x] = map[_y][_x];
            else temp[_y][_x] = map[_y][_x];
        }
    }
    std::copy(&temp[0][0], &temp[50][51], &map[0][0]);
    for (const auto &cleaner : airClean)
        map[cleaner.first][cleaner.second] = -1;

    int sum = 2;
    for(int _y = 1; _y <= y; ++_y)
        for(int _x = 1; _x <= x; ++_x)
            sum += map[_y][_x];
    return sum;
}
void test(int y, int x);
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int y, x, t; cin >> y >> x >> t;
    for(int _y = 1; _y <= y; ++_y)
    {
        for(int _x = 1; _x <= x; ++_x)
        {
            cin >> map[_y][_x];
            if(map[_y][_x] == -1)
                airClean.push_back({_y,_x});
        }
    }

    int res;
    while(t--)
    {
        diffusion(y,x);
        res = clean(y,x);
    }

    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp

void test(int y, int x)
{
    cout << "==============================\n";
    for (int _y = 1; _y <= y; ++_y)
    {
        for (int _x = 1; _x <= x; ++_x)
        {
            cout << map[_y][_x] << ' ';
        }
        cout << '\n';
    }
    cout << "==============================\n";
}