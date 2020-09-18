#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

bool arr[1001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, l; cin >> n >> l;
	if(l == 1) cout << n << '\n';
	else
	{
		for(int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			arr[x] = true;
		}
		
		int cnt = 0;
		l--;
		for(int i = 1; i <= 1000; ++i)
		{
			if(arr[i] == true)
			{
				i += l;
				cnt++;
			}
		}
		
		cout << cnt << '\n';
	}
}