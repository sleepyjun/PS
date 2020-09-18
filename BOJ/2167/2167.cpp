#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
const int INF = 987654321;

int arr[301][301];
int dp[301][301];
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,m; cin >> n >> m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            cin >> arr[i][j];
    
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            dp[i][j] = dp[i-1][j]+dp[i][j-1]+arr[i][j]-dp[i-1][j-1];
        }
    }
    
    int t; cin >> t;
    while(t--)
    {
        int i,j,x,y;
        cin >> i >> j >> x >> y;
        cout << dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1] << '\n'; 
    }
}