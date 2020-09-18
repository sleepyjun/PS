// https://www.acmicpc.net/problem/3896
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 1299710;
bool isprime[MAX];
std::set<int> prime;
void init()
{
	std::fill(isprime,isprime+MAX,true);
	for(int i = 2; i < MAX; ++i)
	{
		if(isprime[i]) prime.insert(i);
		for(int j = i*2; j < MAX; j+=i)
			isprime[j] = false;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	init();
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		if(prime.find(n) != prime.end())
			cout << 0 << '\n';
		else
		{
			auto upper = prime.upper_bound(n);
			int u = *upper; upper--;
			int l = *upper;
			cout << u-l << '\n';
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;