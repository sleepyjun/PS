// https://www.acmicpc.net/problem/1562
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();
const int MOD = 1000000000;

int dp[101][10][(1<<10)];

int func(int len, int idx, int status)
{
	if(len == 0)
	{
		if(status == 1023) return 1;
		return 0;
	}
	int& ret = dp[len][idx][status];
	if(ret != -1) return ret;
	ret = 0;
	
	if(idx-1 >= 0) ret = (ret + func(len-1, idx-1, status|(1<<(idx-1)))) % MOD;
	if(idx+1 <= 9) ret = (ret + func(len-1, idx+1, status|(1<<(idx+1)))) % MOD; 
	
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int len; cin >> len;
	int res = 0;
	std::fill(&dp[0][0][0], &dp[100][9][(1<<10)], -1);
	
	for(int i = 1; i < 10; ++i) res = (res + func(len-1, i, (1<<i)))%MOD;
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;