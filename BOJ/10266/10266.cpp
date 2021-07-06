// https://www.acmicpc.net/problem/10266
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 360000;
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
	
	std::string a(MAX, '0'), b(MAX, '0');
	
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		a[x] = '1';
	}
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		b[x] = '1';
	}
	
	std::string aa = a + a;
	getFail(b);	
	
	for(int i = 0, j = 0; i < aa.length(); ++i)
	{
		while(j > 0 && aa[i] != b[j]) j = fail[j-1];
		if(aa[i] == b[j])
		{
			if(j == b.length()-1)
			{
				cout << "possible\n";
				return 0;
			}
			else j++;
		}
	}
	cout << "impossible\n";
	return 0;
}//g++ -o a -std=c++17 *.cpp