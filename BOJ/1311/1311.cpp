// https://www.acmicpc.net/problem/1311
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int dp[21][1<<21];
int arr[21][21];
int n; 
int run(int idx, int bit)
{
	if(idx == n || bit == (1<<n)-1) return 0;
	
	int &ret = dp[idx][bit];
	
	if(dp[idx][bit] != 0) return ret;
	ret = INF;

	for(int i = 0; i < n; ++i)
	{
		if(!(bit & (1<<i)))
		{
			bit |= (1<<i);
			ret = std::min(ret, run(idx+1, bit) + arr[idx][i]);
			bit &= ~(1<<i);
		}
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> arr[i][j];
	
	cout << run(0,0) << '\n';
}//g++ -o a -std=c++17 *.cpp