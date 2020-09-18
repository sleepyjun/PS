#include <iostream>
#include <vector>
#include <algorithm>
using std::cin; using std::cout;

const int M = 20091101;

int arr[100002];
int pSum[100002];

int once(int n, int k)
{
	std::vector<long long> count(k, 0);
	int ret = 0;
	
	for(int i = 0; i <= n; ++i)
		count[pSum[i]]++;
	
	for(int i = 0; i < k; ++i)
		if(count[i] >= 2)
			ret = (ret + ((count[i] * (count[i]-1))/2)) % M;
	return ret;
}
int many(int n, int k)
{
	std::vector<int> ret(n+1, 0);
	std::vector<int> prev(k,-1);
	
	for(int i = 0; i <= n; ++i)
	{
		if(i>0) ret[i] = ret[i-1];
		else ret[i] = 0;
		
		int loc = prev[pSum[i]];
		if(loc != -1) ret[i] = std::max(ret[i], ret[loc]+1);
		prev[pSum[i]] = i;
	}
	
	return ret.back();
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		std::fill(pSum, pSum+100001, 0);
		int n, k; cin >> n >> k;
		
		for(int i = 1; i <= n; ++i)
			cin >> arr[i];
		
		pSum[1] = arr[1]%k;
		for(int i = 2; i <= n; ++i)
			pSum[i] = ((pSum[i-1] + arr[i])%k);
		
		cout << once(n,k) << ' ' << many(n,k) << '\n';
	}
}