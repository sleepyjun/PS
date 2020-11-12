// https://www.acmicpc.net/problem/17219
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	std::map<std::string, std::string> txt;
	while(n--)
	{
		std::string URL, PW; cin >> URL >> PW;
		txt[URL] = PW;
	}
	while(m--)
	{
		std::string URL; cin >> URL;
		cout << txt[URL] << '\n';
	}
}//g++ -o a -std=c++11 *.cpp