// https://www.acmicpc.net/problem/1016
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

ull func(ull a, ull b)
{
	std::unordered_set<ull> s;
	for(ull i = a; i <= b; ++i)
		s.insert(i);
	for(int i = 2; i <= 1000000; ++i)
	{
		ull temp = i;
		while(b/i >= temp)
		{
			temp*=i;
			const ull d = temp;
			if(a%temp) temp *= (a/temp+1);
			else temp *= (a/temp);
			for(ull j = temp; j <= b; j+=d)
				if(a <= j) s.erase(j);
		}
	}
	return s.size();
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull a,b; cin >> a >> b;
	cout << func(a,b) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;