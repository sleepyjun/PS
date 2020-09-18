#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

// ull distance[51][2];
// //0 is node1 & cir[n] distance
// //1 is node2 & cir[n] distance
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int cnt = 0;
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n; cin >> n;
		while(n--)
		{
			int x, y, r;
			cin >> x >> y >> r;
			r = r*r;
			ull d1 = (x1-x)*(x1-x) + (y1-y)*(y1-y);;
			ull d2 = (x2-x)*(x2-x) + (y2-y)*(y2-y);;
			
			if((d1 <= r && d2 > r) ||
			   (d1 > r && d2 <= r))
				cnt++;
			
		}
		
		cout << cnt << '\n';
	}
}
