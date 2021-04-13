// https://www.acmicpc.net/problem/20937
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
	
	std::map<int, int> arr;
	int n; cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		if(arr[x] != 0) arr[x]++;
		else arr[x] = 1;
	}

	
	int ans = 0;
	while(1)
	{
		bool flag = true;
		for(auto it = arr.rbegin(); it != arr.rend(); ++it)
		{
			if(it->second != 0)
			{
				it->second = it->second - 1;
				flag = false;
			}
		}
		if(flag == true) break;
		ans++;
	}

	cout << ans << '\n';
}//g++ -o a -std=c++11 *.cpp