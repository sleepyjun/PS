// https://www.acmicpc.net/problem/1620
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	std::map<std::string, std::string> index;
	for(int i = 1; i <= n; ++i)
	{
		std::string str; cin >> str;
		std::string num = std::to_string(i);
		index.insert({str,num});
		index.insert({num,str});
	}
	
	for(int i = 0; i < m; ++i)
	{
		std::string str; cin >> str;
		cout << index.find(str)->second << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;