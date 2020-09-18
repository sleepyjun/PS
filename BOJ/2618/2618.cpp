#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
const int INF = 987654321;

std::vector<pii> accident;
int dp[1002][1002];
int res[1002];
int n, w; 

int distance(const pii& a, const pii& b)
{
    return abs(a.first-b.first) + 
        abs(a.second-b.second);
}
int solve(int x=0, int y=0)
{
    int& ret = dp[x][y];
    if(x == w || y == w) return 0;
    if(ret != -1) return ret;
    int maxIdx = std::max(x,y);
    int cop0, cop1;
    if(x==0)
    {
        cop0 = solve(maxIdx+1,y) + distance(accident[maxIdx+1], {1,1});
    }
    else
    {
        cop0 = solve(maxIdx+1,y) + distance(accident[maxIdx+1], accident[x]);
    }
    if(y==0)
    {
        cop1 = solve(x,maxIdx+1) + distance(accident[maxIdx+1], {n,n});
    }
    else
    {
        cop1 = solve(x,maxIdx+1) + distance(accident[maxIdx+1], accident[y]);
    }

    return ret = std::min(cop0, cop1);
}
void find(int x=0, int y=0)
{
    if(x == w || y == w) return;
    
    int maxIdx = std::max(x,y);
    int cop0, cop1;
    if(x==0)
    {
        cop0 = solve(maxIdx+1,y) + distance(accident[maxIdx+1], {1,1});
    }
    else
    {
        cop0 = solve(maxIdx+1,y) + distance(accident[maxIdx+1], accident[x]);
    }
    if(y==0)
    {
        cop1 = solve(x,maxIdx+1) + distance(accident[maxIdx+1], {n,n});
    }
    else
    {
        cop1 = solve(x,maxIdx+1) + distance(accident[maxIdx+1], accident[y]);
    }
    
    if(cop0 < cop1)
    {
        res[maxIdx] = 1;
        find(maxIdx+1,y);
    }
    else
    {
        res[maxIdx] = 2;
        find(x,maxIdx+1);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> w;
    accident.push_back({0,0});
    for(int i = 0; i < w; ++i)
    {
        int x, y; cin >> x >> y;
        accident.push_back({x,y});
    }
    std::fill(&dp[0][0], &dp[1000][1000], -1);
    cout << solve() << '\n';  
    find();
    for(int i = 0; i < w; ++i)
    {
        cout << res[i] << '\n';
    }
}