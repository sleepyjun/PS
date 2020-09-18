// https://www.acmicpc.net/problem/1949
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[10001];
int dp[10001][2];
std::vector<int> adj[10001];

int func(int root, bool good, int pre)
{
	int& ret = dp[root][good];
	if(ret != -1) return ret;
	ret = 0;
	for(int next : adj[root])
	{
		if(pre == next) continue;
		if(good == true)
			ret += func(next, false, root);
		else
			ret += std::max(func(next, true, root), func(next, false, root));
	}
	if(good)
		ret+=arr[root];
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(&dp[0][0], &dp[10000][2], -1);
	
	int n; cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	for(int i = 0; i < n-1; ++i)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << std::max(func(1,true,-1), func(1,false,-1)) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;