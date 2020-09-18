#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1001][3];
int dp[1001][3];
// R G B
int n;
int first;
int func(int current, int prev)
{
	if(current == n) return 0;
	
	int& ret = dp[current][prev];
	if(ret != -1) return ret;
	ret = INF;
	
	if(current == n-1)
	{
		bool flag[3] = {false, false, false};
		flag[first] = true;
		flag[prev] = true;
		for(int i = 0; i < 3; ++i)
			if(flag[i] == false)
				ret = std::min(ret, func(current+1, i) + arr[current][i]);
		
		return ret;
	}
	else
	{
		for(int i = 0; i < 3; ++i)
			if(prev != i)
				ret = std::min(ret, func(current+1, i) + arr[current][i]);
		return ret;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	
	
	int res = INF;
	for(int i = 0; i < 3; ++i)
	{
		std::fill(&dp[0][0], &dp[1000][3], -1);
		first = i;
		res = std::min(res, func(1,first)+arr[0][first]);
	}
	
	cout << res << '\n';
}