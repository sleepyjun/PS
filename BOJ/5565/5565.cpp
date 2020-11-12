// https://www.acmicpc.net/problem/5565
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
	
	int total; cin >> total;
    for(int i = 0; i < 9; ++i)
	{
		int x; cin >> x;
		total -= x;
	}
	cout << total << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;