// https://www.acmicpc.net/problem/1557
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const long long MAX = 200000;
std::map<int, int> arr;

void mu()
{
	arr[1] = 1;
	for(long long i = 1; i <= MAX; ++i)
	{
		for(long long j = i*2; j <= MAX; j += i)
		{
			arr[j] -= arr[i];
		}
	}
}

long long count(long long n)
{
	long long ret = 0;
	for(long long i = 1; i*i <= n; ++i)
	{
		ret += arr[i] * (n /(i*i));
	}
	return n-ret;
}
// 4, 8, 9, 12, 16, 18, 20, 24, 25, 27
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	mu();
	long long k; cin >> k;
	long long l = 0, r = k*4;
	
	while(l<r)
	{
		long long mid = (l+r)/2;
		
		if(count(mid) < k) l = mid+1;
		else r = mid;
	}
	
	cout << r << '\n';
}//g++ -o a -std=c++17 *.cpp