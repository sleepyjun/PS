#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int arr[1001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	
	
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	
	std::vector<int> diff(n);
	diff[0] = 0;
	for(int i = 1; i < n; ++i)
		diff[i] = arr[i-1] - arr[i];

	while(m--)
	{
		std::sort(diff.begin(), diff.end());
		if(diff.back() > 0)
			diff.back()--;
	}
	
	int sum = 0;
	for(int i = 0; i < diff.size(); ++i)
		if(diff[i] > 0)
			sum += diff[i]*diff[i];
	
	cout << sum << '\n';
}