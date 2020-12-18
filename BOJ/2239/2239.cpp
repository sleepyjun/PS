// https://www.acmicpc.net/problem/2239
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();
const int MAX = 9;

int map[MAX][MAX];
bool solved = false;
bool position(int cy, int cx, int n)
{
    int by = (cy/3)*3, bx = (cx/3)*3;
    // 3x3 Block check
    for(int y = by; y < by+3; ++y)
        for(int x = bx; x < bx+3; ++x)
            if(map[y][x] == n) return false;
    // Column check
    for(int y = 0; y < MAX; ++y)
        if(cy != y && map[y][cx] == n) return false;
    // Row check
    for(int x = 0; x < MAX; ++x)
        if(cx != x && map[cy][x] == n) return false;

    return true;
}
void solve(int cy, int cx)
{
    if(true == solved) return;
    if(cx == MAX) solve(cy+1,0);
    if(cy == MAX) 
    {
        solved = true;
        for (int y = 0; y < MAX; ++y)
        {
            for (int x = 0; x < MAX; ++x)
                cout << map[y][x];
            cout << '\n';
        }
        return;
    }

    if(map[cy][cx] == 0)
    {
        for(int i = 1; i <= MAX; ++i)
            if(true == position(cy,cx,i))
            {
                map[cy][cx] = i;
                solve(cy,cx+1);     
                map[cy][cx] = 0;  
            }
    }
    else solve(cy,cx+1);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    for (int y = 0; y < MAX; ++y)
    {
        for (int x = 0; x < MAX; ++x)
        {
            char ch; cin >> ch;
            map[y][x] = ch-'0';
        }
    }
    solve(0,0);
}//g++ -o a -std=c++11 *.cpp