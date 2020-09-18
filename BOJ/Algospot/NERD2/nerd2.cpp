#include <iostream>
#include <algorithm>
#include <map>
using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;

std::map<int, int> coords;
//x is key, y is value;

bool isDominated(int x, int y)
{
	auto it = coords.lower_bound(x);
	if(it == coords.end()) return false;
	
	return y < it->second;
}

void removeDominated(int x, int y)
{
	auto it = coords.lower_bound(x);
	if(it == coords.begin()) return;
	--it;
	while(true)
	{
		if(it->second > y) break;
		if(it == coords.begin())
		{
			coords.erase(it);
			break;
		}
		else
		{
			auto jt = it;
			jt--;
			coords.erase(it);
			it = jt;
		}
	}
}

int registered(int x, int y)
{
	if(isDominated(x,y)) return coords.size();
	
	removeDominated(x,y);
	coords[x] = y;
	return coords.size();
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int res=0;
		for(int i = 0; i < n; ++i)
		{
			int x, y; cin >> x >> y;
			res += registered(x,y);
		}
		cout << res << '\n';
		coords.clear();
	}
}