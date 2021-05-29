// https://www.acmicpc.net/problem/1339
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int idx = 0;
int alpha[26];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::fill(alpha, alpha+26, -1);
	std::vector<std::string> str;
	int n; cin >> n;

	for(int i = 0; i < n; ++i)
	{
		std::string s; cin >> s;
		str.push_back(s);
		for(char ch: s)
		{
			if(alpha[ch-'A'] == -1) alpha[ch-'A'] = idx++;
		}
	}
	std::vector<int> p(idx);
	for(int i = 0; i < idx; ++i) p[i] = 9-i;

	int res = -1;
	do
	{
		int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			int temp = 0;
			for(char ch: str[i])
			{
				int idx = alpha[ch-'A'];

				temp *= 10;
				temp += p[idx];
			}
			sum += temp;
		}
		res = std::max(res, sum);
	} while (std::prev_permutation(p.begin(), p.end()));

	cout << res << '\n';
}//g++ -o a -std=c++17 *.cpp