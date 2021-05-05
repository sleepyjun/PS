// https://www.acmicpc.net/problem/15661
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int stat[21][21];
bool choose[21];
int n; 

int calc(const std::vector<int> v, bool flag)
{
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] == flag)
		{
			for(int j = 0; j < n; ++j)
			{
				if(v[j] == flag)
				{
					sum += stat[i][j];
				}
			}
		}
	}

	return sum;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> stat[i][j];
	
	int min = INF;

	for(int startCnt = 1; startCnt <= n-1; ++startCnt)
	{
		std::vector<int> v(n, 1);
		for(int i = 0; i < startCnt; ++i) v[i] = 0;

		do
		{
			min = std::min(min, abs(calc(v, true)-calc(v, false)));
		} while (std::next_permutation(v.begin(), v.end()));
	}

	cout << min << '\n';
}//g++ -o a -std=c++17 *.cpp