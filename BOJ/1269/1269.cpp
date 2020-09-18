// https://www.acmicpc.net/problem/1269
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	std::set<int> s;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		s.insert(x);
	}
	for(int i = 0; i < m; ++i)
	{
		int x; cin >> x;
		auto it = s.find(x);
		if(it != s.end()) s.erase(it);
		else s.insert(x);
	}
	
	cout << s.size() << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;