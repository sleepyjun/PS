#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <vector>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

bool dp[300];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::string s; cin >> s;
	int n; cin >> n;
	std::vector<std::string> list(n);
	int len = s.length();
	int cnt = 0;
	
	for(int i = 0; i < n; ++i)
		cin >> list[i];
	
	bool flag = false;
	std::queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int x = q.front();
		if(x == len)
		{
			flag = true;
			break;
		}
		if(x > len)
			break;
		q.pop();
		for(const auto& str : list)
		{
			int strLen = str.length();
			if(dp[x+strLen] == true) continue;
			if(s.compare(x,strLen,str) == 0)
			{
				dp[x+strLen] = true;
				q.push(x+strLen);
			}
		}
	}
	
	
	if(flag) cout << 1;
	else cout << 0;
	cout << '\n';
}