#include <iostream>
#include <algorithm>
using namespace std;


int arr[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	
	sort(arr, arr+n+1);
	
	int res = 0;
	for(int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for(int j = 1; j <= i; ++j)
			sum+=arr[j];
		res+=sum;
	}
	cout << res << endl;
}