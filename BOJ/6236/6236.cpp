#include <iostream>
#include <algorithm>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int n, m; 
int src[100001];
bool possible(const int money)
{
	int sum = 0;
	int cnt = 1;
	for(int i = 0; i < n; ++i)
	{
		if(src[i] > money) return false;
		sum += src[i];
		if(sum > money)
		{
			sum = src[i];
			cnt++;
		}
	}
	
	return m >= cnt;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	int low = 1, high = 0;
	int res;
	for(int i = 0; i < n; ++i)
	{
		cin >> src[i];
		high += src[i];
	}
	
	while(low <= high)
	{
		int money = (low+high)/2;
		if(possible(money))
		{
			high = money-1;
			res = money;
		}
		else low = money+1;
	}
	cout << res << '\n';
}