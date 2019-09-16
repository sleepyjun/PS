#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int arr[101];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	int min=999999999, res;
	
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	
	for(int i = 1; i <= n-2; ++i)
	{
		for(int j = i+1; j <= n-1; ++j)
		{
			for(int k = j+1; k <= n; ++k)
			{
				int tSum = arr[i] + arr[j] + arr[k];
				int comp = m-tSum;
				if(comp >= 0 && comp < min)
				{
					min = comp;
					res = tSum;
				}
			}
		}
	}
	
	cout << res << '\n';
}