// https://www.acmicpc.net/problem/5543
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
	
	std::vector<int> ham, drink;
	for(int i = 0; i < 3; ++i)
	{
		int x; cin >> x;
		ham.push_back(x);
	}
	for(int i = 0; i < 2; ++i)
	{
		int x; cin >> x;
		drink.push_back(x);
	}
	int min = INF;
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 2; ++j)
			min = std::min(min, ham[i] + drink[j]);
	cout << min - 50 << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;