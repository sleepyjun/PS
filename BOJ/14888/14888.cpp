#include <iostream>
#include <algorithm>
#include <limits>
using std::cin; using std::cout;

int arr[12];
int calcs[4];

int minRes = std::numeric_limits<int>::max();
int maxRes = std::numeric_limits<int>::min();

int calc(int idx, int con, int res)
{
	switch(con)
	{
		case 0: return res+arr[idx];
		case 1: return res-arr[idx];
		case 2: return res*arr[idx];
		case 3: return res/arr[idx];
	}
}
void dfs(int idx, int cnt, int res)
{
	if(cnt == 0)
	{
		minRes = std::min(minRes, res);
		maxRes = std::max(maxRes, res);
		return;
	}
	
	int temp = res;
	for(int i = 0; i < 4; ++i)
	{
		res = temp;
		if(calcs[i] != 0) 
		{
			calcs[i]--;
			res = calc(idx, i, res);
			dfs(idx+1, cnt-1, res);
			calcs[i]++;
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	for(int i = 0; i < 4; ++i)
		cin >> calcs[i];
	
	dfs(2, n-1, arr[1]);
	
	cout << maxRes << '\n' << minRes << '\n';
}