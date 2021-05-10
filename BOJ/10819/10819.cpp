// https://www.acmicpc.net/problem/10819
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
	
	int n; cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	std::sort(v.begin(), v.end());
	
	int res = -1;
	do
	{
		int sum = 0;
		for(int i = 0; i < n-1; ++i)
			sum += abs(v[i]-v[i+1]);
		res = std::max(res, sum);
	} while(std::next_permutation(v.begin(), v.end()));

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp