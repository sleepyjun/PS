#include <iostream>
#include <algorithm>
using namespace std;

bool dp[102][1002];
// dp[i][x] = i번째 음악을 x볼륨으로 연주 가능한가?
int arr[101];
int N, S, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(&dp[0][0], &dp[101][1001], false);
	
	cin >> N >> S >> M;
	for(int i = 1; i <= N; ++i)
		cin >> arr[i];

	dp[0][S] = true;
	
	for(int i = 1; i <= N; ++i)
		for(int j = 0; j <= M; ++j)
		{
			if(!dp[i-1][j]) continue;
			
			if(j - arr[i] >= 0)
				dp[i][j-arr[i]] = true;
			if(j + arr[i] <= M)
				dp[i][j+arr[i]] = true;
		}
	
	bool flag = true;
	for(int i = M; flag && i >= 0; --i)
		if(dp[N][i] == true)
		{
			flag = false;
			cout << i << endl;
		}
	
	if(flag) cout << -1 << endl;
}