// https://www.acmicpc.net/problem/3041
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <cmath>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

const std::vector<pii> CLEAR = {
	{0,0},{0,1},{0,2},{0,3},
	{1,0},{1,1},{1,2},{1,3},
	{2,0},{2,1},{2,2},{2,3},
	{3,0},{3,1},{3,2},{3,3},
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cnt = 0;
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			char ch; cin >> ch;
			if(ch == '.') continue;
			cnt += abs(i-CLEAR[ch-'A'].first);
			cnt += abs(j-CLEAR[ch-'A'].second);
		}
	}
	cout << cnt << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;