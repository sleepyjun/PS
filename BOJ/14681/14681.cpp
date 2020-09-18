// https://www.acmicpc.net/problem/14681
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
	
	int x,y; cin >> x >> y;
	if(x > 0 && y > 0) cout << 1;
	else if(x < 0 && y > 0) cout << 2;
	else if(x < 0 && y < 0) cout << 3;
	else cout << 4;
	cout << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;