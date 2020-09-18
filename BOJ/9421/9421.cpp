// https://www.acmicpc.net/problem/9421
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

bool isprime[1000001];
std::vector<int> prime;
void init(const int MAX)
{
	std::fill(isprime,isprime+MAX+1,true);
	for(int i = 2; i <= MAX; ++i)
	{
		if(isprime[i]) prime.push_back(i);
		for(int j = i*2; j <= MAX; j+=i)
			isprime[j] = false;
	}
}
int calc(int n)
{
	int sum = 0;
	while(n != 0)
	{
		sum += (n%10)*(n%10);
		n/=10;
	}
	return sum;
}
bool judge(int n)
{
	std::set<int> s;
	s.insert(n);
	while(1)
	{
		n = calc(n);
		if(n == 1) return true;
		else if(s.find(n) != s.end()) return false;
		else s.insert(n);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::vector<int> res;
	int n; cin >> n;
	init(n);
	for(int p: prime)
		if(judge(p)) res.push_back(p);
	for(int r: res)
		cout << r << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;