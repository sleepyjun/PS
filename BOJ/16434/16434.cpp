#include <iostream>
#include <algorithm>
#include <limits>
#include <tuple>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const long long INF = std::numeric_limits<long long>::max();


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	long long n, atk; cin >> n >> atk;
	long long total = 0;
	long long res = -INF;
	for(long long i = 0; i < n; ++i)
	{
		long long t,a,h; cin >> t >> a >> h;
		
		if(t == 1)
		{
			long long turn = h/atk + (h%atk ? 0 : -1);
			total -= turn*a;
			res = std::max(res, -total);
		}
		else
		{
			atk+=a;
			total += h;
			if(total > 0) total = 0;
		}
		
	}
	
	cout << res+1 << '\n';
}
