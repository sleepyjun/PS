#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
typedef unsigned long long ull;
const int INF = 987654321;

int n;
int arr[101][101];
ull dp[101][101];

ull solve(int y, int x)
{
    ull& ret = dp[y][x];
    if(ret != -1) return ret;
    if(y == n-1 && x == n-1) return 1;
    if(y >= n || x >= n) return 0;
    
    int jump = arr[y][x];
    if(jump == 0) return 0;
    return ret = solve(y+jump,x) + solve(y,x+jump);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];
    std::fill(&dp[0][0], &dp[100][100], -1);
    cout << solve(0,0) << '\n';
}