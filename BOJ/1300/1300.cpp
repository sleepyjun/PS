#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int n, k;
int res;
int run(int left, int right)
{
	if(left > right) return left;
	int mid = (left+right)/2;
	long long cnt = 0;
	for(int i = 1; i <= n; ++i)
		cnt += std::min(n,mid/i);
	if(cnt < k) left = mid+1;
	// else { res = mid; cout << mid << '\n'; return 0; }
	else right = mid-1; 
	run(left, right);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	
	
	cout << run(1,k) << '\n';
}