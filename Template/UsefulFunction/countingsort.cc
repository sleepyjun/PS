// https://www.acmicpc.net/problem/10989
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[10001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		arr[x]++;
	}
	for(int i = 1; i <= 10000; ++i)
		for(int j = 0; j < arr[i]; ++j)
			cout << i << '\n';
}//g++ -o a -std=c++11 *.cpp