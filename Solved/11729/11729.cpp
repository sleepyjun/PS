#include <iostream>
#include <algorithm>
using namespace std;

void func(int n, int x, int y)
{
	if(n==0) return;
	func(n-1, x, 6-x-y);
	cout << x << ' ' << y << '\n';
	func(n-1, 6-x-y, y);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	cout << (1 << n)-1 << '\n';
	func(n,1,3);
}