#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	std::vector<int> v(10);
	int cnt = 1;
	for(int i = 0; i < 10; ++i)
	{
		cin >> v[i];
		v[i] %= 42;
	}
	std::sort(v.begin(), v.end());
	for(int i = 1; i < 10; ++i)
	{
		if(v[i-1] != v[i])
			cnt++;
	}
	cout << cnt << '\n';
}