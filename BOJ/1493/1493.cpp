#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

std::vector<pii> v;
int res = 0;
bool possible = true;
void solve(int l, int w, int h)
{
	if(possible == false) return;
	if(l == 0 || w == 0 || h == 0) return;
	
	for(auto &cube : v)
	{
		int size = cube.first;
		int& cnt = cube.second;
		if(size <= l && size <= w && size <= h && cnt)
		{
			res++;
			cnt--;
			solve(l,w,h-size);
			solve(size,w-size,size);
			solve(l-size,w,size);
			return;
		}
	}
	possible = false;
	return;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int l,w,h; cin >> l >> w >> h;
	int n; cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		v.push_back({pow(2,x), y});
	}
	std::sort(v.begin(), v.end(), std::greater<pii>());
	solve(l,w,h);
	if(possible)
		cout << res;
	else
		cout << -1;
	cout << '\n';
}