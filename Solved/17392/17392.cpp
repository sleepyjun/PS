#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
	{
		int ap; cin >> ap;
		m -= (ap+1);
	}
	
	int sum = 0;
	int cnt = 1;
	while(m > 0)
	{
		if(m-(n+1) < 0)
		{
			sum += (cnt*cnt)*m;
			m=0;
		}
		else
		{
			sum += (cnt*cnt)*(n+1);
			m-=(n+1);
		}
		cnt++;
	}
	
	cout << sum << '\n';
}