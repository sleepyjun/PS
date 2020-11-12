// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using std::cin;
using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int DIR[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int N, cSize=2, cEat;
bool visited[21][21];
int map[21][21];
std::vector<std::tuple<int,int,int> > fishes;

bool eatPossible()
{
    for(int y = 1; y <= N; ++y)
        for(int x = 1; x <= N; ++x)
            if(map[y][x] != 0 && map[y][x] < cSize)
                return true;
    return false;
}
/*===========================*/
bool positionChk(int y, int x)
{
    if((y<1 || y>N) || (x<1 || x>N)) return false;
    if(true == visited[y][x]) return false;
    if(map[y][x] > cSize) return false;
    return true;
}
void bfs(int sY, int sX)
{
    int step = 1;
    std::queue<pii> q;
    q.push({sY,sX}); visited[sY][sX]=true;

    while(!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            const auto c = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int ny = c.first + DIR[i][0];
                int nx = c.second + DIR[i][1];
                if (true != positionChk(ny, nx))
                    continue;
                if (map[ny][nx] != 0 && map[ny][nx] < cSize)
                    fishes.push_back(std::make_tuple(step, ny, nx));
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
        step++;
    }
}
pii eat(int& res)
{
    if(true == fishes.empty()) return {-1,-1};
    std::sort(fishes.begin(), fishes.end());
    int y,x,dist;
    std::tie(dist,y,x) = fishes.front();
    map[y][x] = 0;
    cEat++; res+=dist;
    return {y,x};
}
void init()
{
    std::fill(&visited[0][0], &visited[20][21], false);
    fishes.clear();
    if(cSize == cEat)
    {
        cSize++;
        cEat=0;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pii start;
    int res = 0;
    cin >> N;
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            cin >> map[y][x];
            if(map[y][x] == 9)
            {
                map[y][x] = 0;
                start.first = y; 
                start.second = x;
            }
        }
    }

    while(1)
    {
        init();
        if(false == eatPossible()) break;
        bfs(start.first, start.second);
        start = eat(res);
        if(start.first == -1) break;
    }

    cout << res << '\n';
} //g++ -o a -std=c++11 *.cpp