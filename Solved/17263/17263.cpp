#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	std::vector<int> v;
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cout << v[n-1] << '\n';
}