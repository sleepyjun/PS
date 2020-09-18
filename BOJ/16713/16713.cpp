
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1000001];
int xorArr[1000001];

void init(int n)
{
	for(int i = 0; i < n; ++i)
		xorArr[i+1] = (xorArr[i]^arr[i]);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	init(n);
	int res=0;
	while(q--)
	{
		int s,e; cin >> s >> e;
		res = (res^(xorArr[s-1]^xorArr[e]));
	}
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;