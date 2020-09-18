#include <iostream>
#include <algorithm>
#include <functional>
using std::cin; using std::cout;

int arr[100001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	std::sort(arr+1, arr+(n+1), std::greater<int>());
	long long res = -1;
	
	for(int i = 1; i <= n; ++i)
		res = std::max(res, (long long)arr[i]*i);
	
	cout << res << '\n';
}