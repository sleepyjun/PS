#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
typedef long long ll;
const int INF = 987654321;

ll dp[31];
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;

    dp[0] = 1;
    for(int i = 2; i <= n; i+=2)
    {
        dp[i] = dp[i-2] * 3;
        for(int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[j-4] * 2;
        }
    }
    
    cout << dp[n] << '\n';
}