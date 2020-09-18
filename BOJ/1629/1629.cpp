#include <iostream>
#include <algorithm>
#include <limits>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull a,b,c; cin >> a >> b >> c;
	ull res = 1;
	while(b)
	{
		if(b&1)
		{
			res = (res*a)%c;
		}
		a = (a*a)%c;
		b/=2;
	}
	
	cout << res << '\n';
}