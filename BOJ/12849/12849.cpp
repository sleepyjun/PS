// https://www.acmicpc.net/problem/12849
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const ull MOD = 1000000007;

ull dp[8];
int d;
void func(int t)
{
    if(t==d) return;
    ull temp[8];
    std::copy(dp,dp+8,temp);
    temp[0] = (dp[1]+dp[7])%MOD;
    temp[1] = (dp[0]+dp[2]+dp[7])%MOD;
    temp[2] = (dp[1]+dp[3]+dp[6]+dp[7])%MOD;
    temp[3] = (dp[2]+dp[4]+dp[6])%MOD;
    temp[4] = (dp[3]+dp[5])%MOD;
    temp[5] = (dp[4]+dp[6])%MOD;
    temp[6] = (dp[2]+dp[3]+dp[5]+dp[7])%MOD;
    temp[7] = (dp[0]+dp[1]+dp[2]+dp[6])%MOD;
    std::copy(temp,temp+8,dp);
    func(t+1);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> d; dp[0] = 1;
    func(0);
    cout << dp[0] << '\n';
}//g++ -o a -std=c++11 *.cpp