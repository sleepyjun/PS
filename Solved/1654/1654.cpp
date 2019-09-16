#include <iostream>
#include <algorithm>
#include <limits>
using std::cin; using std::cout;

long long arr[10010];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	long long k, n; cin >> k >> n;
	long long cnt = 0;
	long long low = 1;
	long long mid;
	long long high = std::numeric_limits<int>::max();

	long long res = -1;
	for(int i = 1; i <= k; ++i)
		cin >> arr[i];

		while(low <= high)
		{
			cnt = 0;
			mid = (low + high) / 2;
			for(int i = 1; i <= k; ++i)
			{
				cnt += (arr[i]/mid);
			}
			if(cnt < n)
				high = mid-1;
			else
			{
				if(mid > res) res = mid;
				low = mid+1;
			}
		}
	
	cout << res << '\n';
}