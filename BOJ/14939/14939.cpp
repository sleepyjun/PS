// https://www.acmicpc.net/problem/14939
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 10;
const int DIR[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
void push(char map[MAX][MAX], int cy, int cx)
{
    map[cy][cx] = (map[cy][cx] == '#' ? 'O' : '#');

    for(int i = 0; i < 4; ++i)
    {
        int ny = cy+DIR[i][0];
        int nx = cx+DIR[i][1];
        if(ny < 0 || ny >= MAX || nx < 0 || nx >= MAX) continue;
        map[ny][nx] = (map[ny][nx] == '#' ? 'O' : '#');
    }
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	char map[MAX][MAX];
    for(int y = 0; y < MAX; ++y)
        for(int x = 0; x < MAX; ++x)
            cin >> map[y][x];

    int res = INF;
    for(int bit = 0; bit < (1 << MAX); bit++)
    {
        int cnt = 0;
        char replica[MAX][MAX];
        std::copy(&map[0][0], &map[MAX-1][MAX], &replica[0][0]);

        for(int i = 0; i < MAX; ++i)
            if(bit & (1 << i))
            {
                push(replica, 0, i);
                cnt++;
            }

        for(int y = 1; y < MAX; ++y)
        {
            for(int x = 0; x < MAX; ++x)
            {
                if(replica[y-1][x] == 'O')
                {
                    push(replica, y, x);
                    cnt++;
                }
            }
        }

        bool success = true;
        for(int x = 0; success && x < MAX; ++x)
        {
            if(replica[MAX-1][x] == 'O') success = false;
        }
        if(success == true) res = std::min(res, cnt);
    }

    if(res == INF) cout << -1;
    else cout << res;
    cout << '\n';
}//g++ -o a -std=c++11 *.cpp