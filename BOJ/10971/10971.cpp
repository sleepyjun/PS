// https://www.acmicpc.net/problem/10971
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int adj[11][11];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> adj[i][j];
		
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i) v[i] = i;

	int res = INF;
	do
	{
		int sum = 0;
		bool flag = true;

		for(int i = 0; flag && i < n; ++i)
		{
			int s = v[i];
			int e = v[(i+1)%n];

			if(adj[s][e] == 0) flag = false;
			sum += adj[s][e];
		}

		if(true == flag) res = std::min(res, sum);
	} while (std::next_permutation(v.begin(), v.end()));

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp