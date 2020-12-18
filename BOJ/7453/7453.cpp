// https://www.acmicpc.net/problem/7453
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int num[4][4001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 4; ++j)
			cin >> num[j][i];
	
	std::vector<int> AB, CD;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			AB.push_back(num[0][i]+num[1][j]);
			
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			CD.push_back(num[2][i]+num[3][j]);
	std::sort(AB.begin(),AB.end());
	long long res = 0;
	for(int n : CD)
	{
		int x = n*-1;
		auto lo = std::lower_bound(AB.begin(), AB.end(), x);
		auto up = std::upper_bound(AB.begin(), AB.end(), x);
		res += (up-lo);
	}

	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp