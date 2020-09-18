#include <iostream>
#include <algorithm>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int arr[11];
	int res = 0;
	for(int i = 0; i < 11; ++i)
	{
		int v;
		cin >> arr[i] >> v;
		res += v;
	}
	std::sort(arr,arr+11);
	res *= 20;
	res += arr[0];
	for(int i = 1; i < 11; ++i)
		res += arr[i] = arr[i]+arr[i-1];
	
	cout << res << '\n';
}