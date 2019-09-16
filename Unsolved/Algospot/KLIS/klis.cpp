#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

const int MAX = 2000000000+1;
int n, k;
int len[501], cnt[501], arr[501];

int lis(int start)
{
	int& ret = len[start+1];
	if(ret != -1) return ret;
	
	ret = 1;
	for(int next = start+1; next < n; ++next)
		if(start == -1 || arr[start] < arr[next])
			ret = std::max(ret, lis(next) + 1);
	return ret;
}

int count(int start)
{
	if(lis(start) == 1) return 1;
	int& ret = cnt[start+1];
	if(ret != -1) return ret;
	ret = 0;
	for(int next = start+1; next < n; ++next)
	{
		if((start == -1 || arr[start] < arr[next]) &&
		   (lis(start) == list(next)+1))
			ret = std::min<long long>(MAX, (long long)ret + count(next));
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
		std::fill(arr, arr+501, 0);
		std::fill(len, len+501, -1);
		std::fill(cnt, cnt+501, 0);
		cin >> n >> k;
		for(int i = 0; i < n; ++i)
			cin >> arr[i];
	}
}