// https://www.acmicpc.net/problem/5052
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		bool find;
		int n; cin >> n;
		std::vector<std::string> v(n);
		for(int i = 0; i < n; ++i)
			cin >> v[i];
		std::sort(v.begin(), v.end());

		for(int i = 0; i < n-1; ++i)
		{
			find = true;
			const std::string &a = v[i];
			const std::string &b = v[i+1];
			
			for(int j = 0; j < a.length(); ++j)
				if(a[j] != b[j]) { find = false; break; }
			if(true == find) break;
		}
		if(true == find) cout << "NO\n";
		else cout << "YES\n";
		v.clear();
	}
}//g++ -o a -std=c++11 *.cpp