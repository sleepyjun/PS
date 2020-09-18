#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, v; cin >> a >> b >> v;
	cout << (v-b-1)/(a-b)+1 << '\n';
}