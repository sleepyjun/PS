#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
typedef unsigned long long ull;
const int INF = 987654321;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    int dp[101] = {};
    for(int i = 1; i <= 100; ++i)
    {
        for(int j = i; j <= 100; j += i)
        {
            dp[j]++;
        }
    }
    while(t--)
    {
        int n; cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
            if(dp[i] % 2 == 1) cnt++;
        cout << cnt << '\n';
    }
}