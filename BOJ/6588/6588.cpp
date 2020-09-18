// https://www.acmicpc.net/problem/6588
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

const int MAX = 1000000;
bool isprime[MAX];
std::set<int> prime;
void init()
{
	std::fill(isprime, isprime+MAX, true);
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
	
	init(); prime.erase(prime.begin());
	while(1)
	{
		int n; cin >> n;
		if(n == 0) return 0;
		for(int p: prime)
		{
			if(p > n) 
			{
				cout << "Goldbach's conjecture is wrong.\n";
				break;
			}
			int dest = n-p;
			if(prime.find(dest) != prime.end())
			{
				cout << n << " = " << p << " + " << dest << '\n';
				break;
			}
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;