#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[301];
int arr[301];
int N;

int main()
{
    int MAX = -1;

    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> arr[i];
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3; i <= N; ++i)
        dp[i] = max(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2]);

    cout << dp[N];
    return 0;
}
