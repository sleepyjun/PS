#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef unsigned long long ull;

map<ull, ull> m; //key, value;
ull n, p, q;

ull dp(ull _n)
{
	if(m.find(_n) != m.end())
		return m[_n];
	
	m.insert(make_pair(_n, dp(_n/p) + dp(_n/q)));
	return m[_n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> p >> q;
	
	m.insert(make_pair(0,1)); //A, i;
	
	cout << dp(n) << '\n';
}