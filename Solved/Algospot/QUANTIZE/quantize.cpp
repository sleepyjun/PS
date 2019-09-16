#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

const int INF = 9999999;
int arr[101];
int pSum[101], pSqSum[101];
int dp[101][11];
int n, s; 
//idx start from 1
void preCal()
{
	std::sort(arr,arr+n+1);
	pSum[1] = arr[1];
	pSqSum[1] = arr[1] * arr[1];
	for(int i = 2; i <= n; ++i)
	{
		pSum[i] = pSum[i-1] + arr[i];
		pSqSum[i] = pSqSum[i-1] + arr[i]*arr[i];
	}
}
int calDiff(int from, int to)
{
	int len = to-from+1;
	int sum = pSum[to] - (from == 1 ? 0 : pSum[from-1]);
	int sqSum = pSqSum[to] - (from == 1 ? 0 : pSqSum[from-1]);
	int m = (int)(0.5 + ((double)sum/len));
	return (len*m*m)+(sqSum)-(2*sum*m);
}
int func(int from, int remain)
{
	if(from == n+1) return 0;
	if(remain == 0) return INF;
	
	int& ret = dp[from][remain];
	if(ret != -1) return ret;
	ret = INF;
	for(int size = 1; from+size <= n+1; ++size)
	{
		ret = std::min(ret, func(from+size, remain-1) + calDiff(from, from+size-1));
	}
	
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(pSum, pSum+101, 0);
		std::fill(pSqSum, pSqSum+101, 0);
		std::fill(&dp[0][0], &dp[100][10], -1);
		
		cin >> n >> s;
		for(int i = 1; i <= n; ++i)
			cin >> arr[i];
		preCal();
		cout << func(1,s) << '\n';
	}
}