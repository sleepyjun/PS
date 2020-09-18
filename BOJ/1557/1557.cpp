// https://www.acmicpc.net/problem/1557
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

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull k; cin >> k;
	ull res = 0;
	for(ull i = 1; i <= k;)
	{	
		ull temp = 2;
		bool flag = true;
		res++;
		ull sqrtRes = (ull)sqrt(res);
		while(temp <= sqrtRes)
		{
			if(res % (temp*temp) == 0)
			{
				flag = false;
				break;
			}
			temp++;
		}
		if(flag)
			i++;
	}
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;