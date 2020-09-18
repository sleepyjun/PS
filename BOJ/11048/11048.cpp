#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
typedef long long ll;
const int INF = 987654321;

int maze[1010][1010];
int dp[1010][1010];
int n, m; 
int solve(int y, int x)
{
    int& ret = dp[y][x];
    if(ret != -1) return ret;
    if(y==0 || x==0) return 0;
    ret = maze[y][x];
    
    return ret += std::max(solve(y-1,x-1),std::max(solve(y-1,x),solve(y,x-1)));
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    std::fill(&dp[0][0], &dp[1009][1009], -1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> maze[i][j];
    
    cout << solve(n,m) << '\n';
}