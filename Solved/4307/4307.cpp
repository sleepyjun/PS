#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	while(T--)
	{
		fill(&arr[0], &arr[999999], 0);
		int n, cnt; cin >> n >> cnt;
		for(int i = 0; i < cnt; ++i)
			cin >> arr[i];
		sort(arr, arr+cnt);
		
		int fast = -1;
		for(int i = 0; i < cnt; ++i)
		{
			if(arr[i] <= n/2)
			{
				fast = max(fast, arr[i]);
			}
			else
			{
				fast = max(fast, n-arr[i]);
			}
		}
		int slow = max(n-arr[0], arr[cnt-1]);
		
		cout << fast << ' ' << slow << endl;
	}
}