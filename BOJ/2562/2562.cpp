#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int max = -1, idx = -1;
	for(int i = 1; i <= 9; ++i)
	{
		int temp; cin >> temp;
		if(temp > max)
		{
			max = temp;
			idx = i;
		}
	}
	
	cout << max << ' ' << idx << '\n';
}