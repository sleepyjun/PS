#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, ans=0; cin >> n;
	std::vector<int> v;
	v.push_back(-1);
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		if(v.back() < x)
		{
			v.push_back(x);
			ans++;
		}
		else
		{
			auto it = std::lower_bound(v.begin(),v.end(),x);
			*it = x;
		}
	}
	cout << ans << '\n';
}