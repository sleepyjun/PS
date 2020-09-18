#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
typedef unsigned long long ull;
const int INF = 987654321;

int dp[201][201];
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k; cin >> n >> k;
    const int MOD = 1000000000;
    
    for(int i = 0; i <= 200; ++i)
    {
        dp[0][i] = 1;
    }
        
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            for(int x = i; x >= 0; --x)
                dp[i][j] = (dp[i][j] + dp[x][j-1]) % MOD;
        }
    }
    
    cout << dp[n][k] << '\n';;

}