#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int arr[51][2];
int res[51];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i][0] >> arr[i][1];
	
	for(int i = 1; i <= n; ++i)
	{
		int cnt = 1;
		for(int j = 1; j <= n; ++j)
		{
			if(arr[i][0] < arr[j][0] && 
			  arr[i][1] < arr[j][1])
				cnt++;
		}
		res[i] = cnt;
	}
	
	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << ' ';
	}
	cout << '\n';
}