#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int weight[101];
int value[101];
int dp[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; ++i)
		cin >> weight[i] >> value[i];
	
	for(int i = 0; i < n; ++i)
		for(int j = k; j >= weight[i]; --j)
			dp[j] = std::max(dp[j], dp[j-weight[i]] + value[i]);
	
	cout << dp[k] << '\n';
}