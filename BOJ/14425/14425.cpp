// https://www.acmicpc.net/problem/14425
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <unordered_set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::unordered_set<std::string> set;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	int cnt = 0;
	
	for(int i = 0; i < n; ++i)
	{
		std::string str; cin >> str;
		set.insert(str);
	}
	for(int i = 0; i < m; ++i)
	{
		std::string str; cin >> str;
		if(set.find(str) != set.end()) cnt++;
	}
	
	cout << cnt << '\n';
}//g++ -o a -std=c++17 *.cpp