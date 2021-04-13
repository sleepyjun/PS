// https://www.acmicpc.net/problem/4375
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
	
	while(1)
	{
		int n; cin >> n;
		if(cin.eof()) return 0;
		int tenMod = 1;
		int mod = 1;
		int cnt = 1;
		while(1)
		{
			if(mod % n == 0) break;
			tenMod = (tenMod*10)%n;
			mod = (mod + tenMod)%n;
			cnt++;
		}
		cout << cnt << std::endl;
	}
}//g++ -o a -std=c++11 *.cpp