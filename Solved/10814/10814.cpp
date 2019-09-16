#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::vector<std::pair<int, std::pair<int, std::string> > > vpp;
	int n; cin >> n;
	vpp.resize(n);
	
	for(int i = 0; i < n; ++i)
	{
		vpp[i].second.first = i;
		cin >> vpp[i].first >> vpp[i].second.second;
	}
	std::sort(vpp.begin(), vpp.end());
	
	for(int i = 0; i < n; ++i)
	{
		cout << vpp[i].first << ' ' << vpp[i].second.second << '\n';
	}
}