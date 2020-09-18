#include <iostream>
#include <algorithm>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[100001];
int n, m;
bool possible(const int time)
{
	int sum = 0;
	int num = 1;
	for(int i = 0; i < n; ++i)
	{
		if(arr[i] > time) return false;
		sum += arr[i];
		if(sum > time)
		{
			sum = arr[i];
			num++;
		}
	}
	return m >= num;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	int low = 1, high = sum;
	int res;
	while(low <= high)
	{
		int mid = (high + low) / 2;
		if(possible(mid))
		{
			res = mid;
			high = mid-1;
		}
		else
			low = mid+1;
	}
	
	cout << res << '\n';
}