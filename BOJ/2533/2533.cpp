// https://www.acmicpc.net/problem/2533
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> adj[1000001];
int dp[1000001][2];
int func(int root, bool isAdaptor, int pre)
{
	int& ret = dp[root][isAdaptor];
	if(ret != -1) return ret;
	ret = 0;
	for(int next : adj[root])
	{
		if(next == pre) continue;
		if(isAdaptor)
			ret += std::min(func(next,false,root), func(next,true,root));
		else
			ret += func(next,true,root);
	}
	
	if(isAdaptor) ret++;
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::fill(&dp[0][0], &dp[n+2][2], -1);
	for(int i = 0; i < n-1; ++i)
	{
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	cout << std::min(func(1,true,-1), func(1,false,-1)) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;