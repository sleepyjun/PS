#include <iostream>
#include <algorithm>
#include <cmath>
using std::cin; using std::cout;

typedef unsigned long long ull;

ull func(ull x)
{
	
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull x; cin >> x; 
	int n; cin >> n;
	
	ull t = x;
	int cnt = 0;
	int po = 0;
	while(t)
	{
		if(t&1) cnt++;
		t >>= 1;
		po++;
	}
	if(cnt < n) cout << -1 << '\n';
	else
	{
		ull m = pow(2,po-1);
		for(int i = 1; i <= n-1;)
		{
			if(x&m) 
			{
				x-=m;
				cout << x << ' ';
				++i;
			}
			m >>= 1;
		}
		cout << 0 << '\n';
	}
}