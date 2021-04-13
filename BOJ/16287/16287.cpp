// https://www.acmicpc.net/problem/16287
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> arr;
int dp[800000];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int w, n; cin >> w >> n;
	arr.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	std::fill(dp,dp+800000,-1);
	for(int i = 0; i < n; ++i)
	{
		if(w < arr[i]) continue;
		for(int j = i+1; j < n; ++j)
		{
			int sum = arr[i]+arr[j];
			if(w < sum) continue;
			if(dp[w-sum] != -1 && dp[w-sum] < std::min(i,j))
			{
				cout << "YES\n";
				return 0;
			}
			dp[sum] = std::max(dp[sum], std::max(i,j));
		}
	}
	cout << "NO\n";
	return 0;
}//g++ -o a -std=c++11 *.cpp