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

int visited[1001][1001];
char map[1001][1001];
int group = 1;

int func(int cy, int cx)
{
    int &ret = visited[cy][cx];
    if(ret != 0) return ret;
    ret = group;

    switch(map[cy][cx])
    {
        case 'U': ret=std::min(ret,func(cy-1,cx)); break;
        case 'D': ret=std::min(ret,func(cy+1,cx)); break;
        case 'L': ret=std::min(ret,func(cy,cx-1)); break;
        case 'R': ret=std::min(ret,func(cy,cx+1)); break;
    }
    return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int y,x; cin >> y >> x;
    for(int i = 0; i < y; ++i)
        for(int j = 0; j < x; ++j)
            cin >> map[i][j];

    for(int i = 0; i < y; ++i)
    {
        for(int j = 0; j < x; ++j)
        {
            if(visited[i][j] != 0) continue;
            else
            {
                if(group == func(i,j))
                    group++;
            }
        }
    }
    cout << group - 1 << '\n';
}//g++ -o a -std=c++11 *.cpp