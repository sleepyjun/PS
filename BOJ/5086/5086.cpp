#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(1)
	{
		int x,y; cin >> x >> y;
		if(x == 0 && x == y)
			break;
		if(y%x == 0) cout << "factor" << '\n';
		else if(x%y == 0) cout << "multiple" << '\n';
		else cout << "neither" << '\n';
	}
}