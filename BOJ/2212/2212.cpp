#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k; cin >> n >> k;
	std::vector<int> v(n), d(n-1);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	std::sort(v.begin(), v.end());
	int res = v[n-1]-v[0];
	for(int i = 1; i < n; ++i)
		d[i-1] = v[i]-v[i-1];
	std::sort(d.begin(), d.end(), std::greater<int>());
	for(int i = 0; i < k-1 && i < n-1; ++i)
		res -= d[i];
	
	cout << res << '\n';
}