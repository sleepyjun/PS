// https://www.acmicpc.net/problem/1100
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cnt = 0;
	char ch;
	for(int y = 0; y < 8; ++y)
	{
		for(int x = 0; x < 8; ++x)
		{
			cin >> ch;
			if(ch == 'F')
			{
				if(y%2==0 && x%2==0)
					cnt++;
				else if(y%2==1 && x%2==1)
					cnt++;
			}
		}
	}
	
	cout << cnt << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;