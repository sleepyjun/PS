// https://www.acmicpc.net/problem/16139
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int sumArr[26][200001];

void init(const std::string& s)
{
	for(int i = 0; i < s.length(); ++i)
	{
		int idx = s[i] - 'a';
		sumArr[idx][i] = 1;
		if(i == 0) continue;
		for(int j = 0; j < 26; ++j)
			sumArr[j][i] += sumArr[j][i-1];
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::string s; cin >> s;
	int q; cin >> q;
	init(s);
	while(q--)
	{
		char ch; cin >> ch;
		int l, r; cin >> l >> r;
		if(l == 0)
			cout << sumArr[ch-'a'][r];
		else
			cout << sumArr[ch-'a'][r] - sumArr[ch-'a'][l-1];
		cout << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;