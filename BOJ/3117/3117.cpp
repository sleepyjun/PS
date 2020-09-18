// https://www.acmicpc.net/problem/3117
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int table[100001][30];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,k,m; cin >> n >> k >> m;
	std::vector<int> resList(n);
	for(int i = 0; i < n; ++i)
		cin >> resList[i];
	for(int i = 1; i <= k; ++i)
		cin >> table[i][0];
	for(int p = 1; p < 30; ++p)
		for(int i = 1; i <= k; ++i)
			table[i][p] = table[table[i][p-1]][p-1];
	
	for(int res: resList)
	{
		int time = m-1;
		for(int i = 29; i >= 0; --i)
		{
			if(time >= (1<<i))
			{
				time -= (1<<i);
				res = table[res][i];
			}
		}
		cout << res << ' ';
	}
	cout << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;