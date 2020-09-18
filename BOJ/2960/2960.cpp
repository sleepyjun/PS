// https://www.acmicpc.net/problem/2960
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool isprime[1001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,k; cin >> n >> k;
	int cnt = 0;
	std::fill(isprime,isprime+1001,true);
	for(int i = 2; i <= n; ++i)
	{
		if(isprime[i])
		{
			cnt++;
			if(cnt == k)
			{
				cout << i << '\n';
				return 0;
			}
		}
		for(int j = i*2; j <= n; j += i)
		{
			if(isprime[j])
			{
				isprime[j] = false;
				cnt++;
				if(cnt == k)
				{
					cout << j << '\n';
					return 0;
				}
			}
		}
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;