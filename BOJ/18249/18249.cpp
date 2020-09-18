#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();
const int MOD = 1000000007;
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	ull arr[191230];
	arr[0] = arr[1] = 1;
	for(int i = 2; i <= 191229; ++i)
	{
		arr[i] = (arr[i-2] + arr[i-1])%MOD;
	}
	while(n--)
	{
		int k; cin >> k;
		cout << arr[k] << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c+=11 \;