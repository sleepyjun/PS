#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>
#include <queue>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::queue<int> q[21]; //idx 0 empty;
	long long cnt = 0;
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
	{
		std::string name; cin >> name;
		int len = name.length();

		while(abs(q[len].front() - i) > k)
		{
			if(true == q[len].empty()) break;
			q[len].pop();
		}
		cnt += q[len].size();
		q[len].push(i);
	}
	
	cout << cnt << '\n';
}