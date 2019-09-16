#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int arr[51];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	std::sort(arr, arr+n);
	if(n%2 == 0)
	{
		cout << arr[0]*arr[n-1] << '\n';
	}
	else
	{
		cout << arr[n/2]*arr[n/2] << '\n';
	}
}