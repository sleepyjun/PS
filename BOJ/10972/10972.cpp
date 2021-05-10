// https://www.acmicpc.net/problem/10972
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
	
	bool flag = std::next_permutation(v.begin(), v.end());
	if(false == flag) cout << -1;
	else for(int i : v)
		cout << i << ' ';
	cout << '\n';
}//g++ -o a -std=c++17 *.cpp