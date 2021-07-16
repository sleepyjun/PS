// https://www.acmicpc.net/problem/2038
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

std::map<int, int> arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	int i = 1;
	int count = 1;
	arr[0] = 1;
	for(; i <= n; ++i)
	{
		arr[i] = 1 + arr[i - arr[arr[i-1]]];

		count += arr[i];
		if(count > n) break;
	}

	cout << i << '\n';
}//g++ -o a -std=c++17 *.cpp