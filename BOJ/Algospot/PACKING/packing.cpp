#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using std::cin; using std::cout;

std::vector<std::pair<std::string, std::pair<int, int> > > v;
//first = string
//second.first = weight
//second.second = important
int n,w;
int dp[1001][100];
std::vector<std::string> res;

int func(int remain, int idx)
{
	if(idx >= n) return 0;
	
	int& ret = dp[remain][idx];
	if(ret != -1) return ret;
	
	ret = func(remain, idx+1);
	if(remain >= v[idx].second.first)
		ret = std::max(ret, func(remain-v[idx].second.first, idx+1)+v[idx].second.second);
	
	return ret;
}

void backtracking(int remain, int idx)
{
	if(idx == n) return;
	if(func(remain, idx) == func(remain, idx+1))
		backtracking(remain, idx+1);
	else
	{
		res.push_back(v[idx].first);
		backtracking(remain-v[idx].second.first, idx+1);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> w;
		std::fill(&dp[0][0], &dp[1000][99], -1);
		res.clear(); v.clear(); v.resize(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i].first >> 
				v[i].second.first >> v[i].second.second;
		}
		backtracking(w, 0);
		cout << dp[w][0] << ' ' << res.size() << '\n';
		for(int i = 0; i < res.size(); ++i)
			cout << res[i] << '\n';
	}
}