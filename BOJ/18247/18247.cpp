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
	
	const int L = 12;
	int t; cin >> t;
	while(t--)
	{
		int n,m; cin >> n >> m;
		if(n < 12 || m < 4)
		{
			cout << -1 << '\n';
			continue;
		}
		cout << (L-1)*m+4 << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;