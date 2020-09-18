#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int h,m; cin >> h >> m;
	m -= 45;
	if(m < 0)
	{
		h--;
		m = 60+m;
	}
	if(h < 0)
		h = 24+h;
	
	cout << h << ' ' << m << '\n';
}