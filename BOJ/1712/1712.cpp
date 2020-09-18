#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	long long a,b,c; cin >> a >> b >> c;
	long long m = c-b;
	if(m <= 0)
		cout << -1 << '\n';
	else
		cout << 1000/m+1 << '\n';
}