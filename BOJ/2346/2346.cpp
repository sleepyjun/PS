#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<pii> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i+1;
	}
	int target = 0;
	while(1)
	{
		cout << v[target].second << ' ';
		int w = v[target].first;
		
		if(w>0)w--;
		
		v.erase(v.begin()+target);
		if(v.empty()) break;
		target += w;
	
		target = (target >= 0 ? target : -(-target % v.size()) + v.size());
		target %= v.size();
	}
	cout << '\n';
}