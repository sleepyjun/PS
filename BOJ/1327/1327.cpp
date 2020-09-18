// https://www.acmicpc.net/problem/1327
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>
#include <queue>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	std::string str;
	
	for(int i = 0; i < n; ++i)
	{
		char ch; cin >> ch;
		str += ch;
	}
	
	std::string RES = str;
	std::sort(RES.begin(), RES.end());
	
	if(RES == str)
	{
		cout << 0 << '\n';
		return 0;
	}
	int lv = 0;
	bool flag = true;
	std::map<std::string, bool> reveal;
	std::queue<std::string> q;
	q.push(str);
	reveal.insert({str, true});
	while(!q.empty() && flag)
	{
		int qSize = q.size();
		for(int i = 0; i < qSize && flag; ++i)
		{
			auto curr = q.front(); q.pop();
			for(int idx = 0; idx < (n-k+1); ++idx)
			{
				auto nStr = curr;
				std::reverse(nStr.begin()+idx, nStr.begin()+idx+k);
				
				if(nStr == RES)
				{
					flag = false;
					break;
				}
				if(reveal.find(nStr) != reveal.end()) continue;
				reveal.insert({nStr, true});
				q.push(nStr);
			}
		} 
		lv++;
	}
	
	if(flag) cout << -1;
	else cout << lv;
	cout << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;