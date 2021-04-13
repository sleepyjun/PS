// https://www.acmicpc.net/problem/1748
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	std::pair<int, int> p;
	p.first = 10123;
	int sum = 0;
	int n; cin >> n;
	int arr[123];
	for(int x: arr)
	{
		
	}
	for(int i = 1; i <= n; i*=10)
	{
		sum += n-i+1;
	}
	cout << sum << '\n';
}//g++ -o a -std=c++11 *.cpp