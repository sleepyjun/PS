// https://www.acmicpc.net/problem/1484
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
	
	int g; cin >> g;
	int s=1,e=1;
	bool flag = false;
	while(1)
	{
		int dg = e*e-s*s;
		if(dg >= g)
		{
			if(dg==g)
			{
				flag = true;
				cout << e << '\n';
			}
			s++;
		}
		else if(((s+1)*(s+1)-(s*s)) > g) break;
		else e++;
	}
	if(false == flag) cout << -1 << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;