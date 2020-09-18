#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<pii> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i].second >> v[i].first;
	std::sort(v.begin(), v.end(), std::greater<pii>());
	int res = 0;
	for(int i = 0; i < n; ++i)
	{
		int limitDay = v[i].second;
		int score = v[i].first;
		for(int j = limitDay; j >= 1; --j)
		{
			if(arr[j] == 0)
			{
				res += score;
				arr[j] = score;
				break;
			}
		}
	}
	
	cout << res << '\n';
}