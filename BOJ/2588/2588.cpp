#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x, y;
	cin >> x >> y;
	cout << (x*(y%10)) << '\n';
	cout << (x*((y/10)%10)) << '\n';
	cout << (x*(y/100)) << '\n';
	cout << (x*y) << '\n';
	
}