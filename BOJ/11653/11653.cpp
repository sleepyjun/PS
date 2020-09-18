#include <iostream>
#include <algorithm>
#include <cmath>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int max = n;
	for(int i = 2; i <= max && n != 0; ++i)
	{
		while(n%i == 0)
		{
			cout << i << '\n';
			n/=i;
		}
	}
}