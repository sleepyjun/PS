#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using std::cin; using std::cout;

typedef std::pair<int, int> pii;
typedef long long ll;
const int INF = 987654321;

int arr[1001];
int dp[1001];
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    int res = -1;
    for(int i = 0; i < n; ++i)
    {
        dp[i] = arr[i];
        for(int j = 0; j < i; ++j)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = std::max(dp[i], dp[j]+arr[i]); 
            }
        }
        res = std::max(res, dp[i]);
    }
    
    cout << res << '\n';
}