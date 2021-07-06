// https://www.acmicpc.net/problem/4354
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 1000001;

int fail[MAX];

void getFail(const std::string &str)
{
	int n = str.length();
	for(int i = 1, j = 0; i < n; ++i)
	{
		while(j > 0 && str[i] != str[j]) j = fail[j-1];
		if(str[i] == str[j]) fail[i] = ++j;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		std::fill(fail, fail+MAX, 0);
		std::string str; cin >> str;
		if(str == ".") break;
		
		int n = str.length();
		getFail(str);
		
		cout << ((n%(n-fail[n-1]) == 0) ? (n/(n-fail[n-1])) : 1) << '\n';
	}
	
	return 0;
}//g++ -o a -std=c++17 *.cpp