#include <iostream>
#include <algorithm>

using std::cin; using std::cout;

int arr[300000];
int partSum[300001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	std::sort(arr, arr+n);
	
	for(int i = 1; i <= n; ++i)
	{
		partSum[i] = partSum[i-1] + arr[i-1];
	}
	
	while(q--)
	{
		int l, r; cin >> l >> r;
		cout << partSum[r] - partSum[l-1] << '\n';
	}
}