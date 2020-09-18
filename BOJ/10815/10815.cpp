#include <iostream>
#include <algorithm>
#include <limits>
#include <set>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::set<int> s;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		s.insert(x);
	}
	int t; cin >> t;
	while(t--)
	{
		int x; cin >> x;
		auto it = s.find(x);
		if(it == s.end())
			cout << "0 ";
		else
			cout << "1 ";
	}
	cout << '\n';
}