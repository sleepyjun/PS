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

const long long MAX = 100000;
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
	return ret;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	mu();
	long long k; cin >> k;
	
	long long l = 0, r = k*2;
	
	while(l<r)
	{
		long long mid = (l+r)/2;
		
		if(count(mid) < k) l = mid+1;
		else r = mid;
	}
	
	cout << r << '\n';
}//g++ -o a -std=c++17 *.cpp

// https://ohgym.tistory.com/19
// https://eine.tistory.com/entry/이진-탐색-이분-탐색binary-search-구현시-고려할-것들