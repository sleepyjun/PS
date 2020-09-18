// https://www.acmicpc.net/problem/1644
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

bool isprime[4000001];
std::vector<int> prime;
void init(const int MAX)
{
	std::fill(isprime, isprime+MAX+1, true);
	for(int i = 2; i <= MAX; ++i)
	{
		if(true == isprime[i])
			prime.push_back(i);
		for(int j = i*2; j <= MAX; j+=i)
			isprime[j] = false;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	init(n);
	int cnt=0,sum=0,s=0,e=0;
	while(1)//[s,e)
	{
		if(sum >= n) sum -= prime[s++];
		else if(prime.size() == e) break;
		else sum += prime[e++];
		if(sum == n) cnt++;
	}
	cout << cnt << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;