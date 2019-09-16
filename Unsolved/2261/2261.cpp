#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

typedef std::pair<int, int> pii; 
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	std::vector<pii> v;
	
	for(int i = 0; i < n; ++i)
	{
		pii p; cin >> p.first >> p.second; //x,y order
		v.push_back(p);	
	}
	sort(v.begin(), v.end());
	
	int len = v[1].second - v[0].second;
}