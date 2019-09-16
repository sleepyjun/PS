#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	 
	std::vector<std::pair<int, int> > vp;
	int n; cin >> n;
	vp.resize(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> vp[i].second >> vp[i].first;
	}
	sort(vp.begin(), vp.end());
	
	for(int i = 0; i < n; ++i)
	{
		cout << vp[i].second << ' ' << vp[i].first << '\n';
	}	
}