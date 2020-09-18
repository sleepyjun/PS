// https://www.acmicpc.net/problem/1456
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

const int MAX = 10000000;
bool isprime[MAX+1];
std::set<ull> prime;
void init(ull b)
{
	int M = b;
	if(b > MAX) M = MAX;
	std::fill(isprime,isprime+MAX+1,true);
	for(ull i = 2; i <= M; ++i)
	{
		if((ull)i > b/i) break;
		if(isprime[i])
		{
			ull temp = i;
			while(b/i >= temp)
			{
				temp*=i;
				prime.insert(temp);
			}
		}
		for(ull j = i*2; j <= M; j+=i)
			isprime[j] = false;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull a,b; cin >> a >> b;
	init(b);
	auto A = prime.lower_bound(a);
	int res = std::distance(prime.begin(), A);
	cout << prime.size() - res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;