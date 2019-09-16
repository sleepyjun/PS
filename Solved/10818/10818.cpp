#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n; 
	std::vector<int> v(n);
	
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	std::sort(v.begin(), v.end());
	cout << v.front() << ' ' << v.back() << '\n';
}