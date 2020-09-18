// https://www.acmicpc.net/problem/2096
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
	
	int n; cin >> n;
	int cMax[3] = {0,}, cMin[3] = {0,}, tMax[3] = {0,}, tMin[3] = {0,};
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			cin >> tMax[j];
			tMin[j] = tMax[j];
			if(j==1)
			{
				tMax[j] += std::max(cMax[0], std::max(cMax[1], cMax[2]));
				tMin[j]	+= std::min(cMin[0], std::min(cMin[1], cMin[2]));
			}
			else
			{
				tMax[j] += std::max(cMax[1], cMax[j]);
				tMin[j] += std::min(cMin[1], cMin[j]);
			}
		}
		std::copy(tMax,tMax+3,cMax);
		std::copy(tMin,tMin+3,cMin);
	}
	std::sort(cMax, cMax+3); std::sort(cMin, cMin+3);
	cout << cMax[2] << ' ' << cMin[0] << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;