#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	if(a>b)
		cout << '>' << '\n';
	else if(a<b)
		cout << '<' << '\n';
	else
		cout << "==" << '\n';
}