// https://www.acmicpc.net/problem/10974
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
		v[i] = i+1;
	
	do
	{
		for(int x: v)
			cout << x << ' ';
		cout << '\n';
	} while(std::next_permutation(v.begin(), v.end()));

}//g++ -o a -std=c++17 *.cpp