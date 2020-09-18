
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1001];
int sumArr[1001];

void init(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		int idx = i-1, prev = i-1;
		sumArr[i] = sumArr[prev] + arr[idx];
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		
		int n; cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> arr[i];
		init(n);
		int max = -INF;
		for(int i = 0; i <= n; ++i)
			for(int j = i+1; j <= n; ++j)
				max = std::max(max, sumArr[j]-sumArr[i]);
		cout << max << '\n';
		std::fill(arr, arr+n+1, 0);
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;