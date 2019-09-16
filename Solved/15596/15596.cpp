#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

long long sum(std::vector<int>& a)
{
	long long res = 0;
	for(int i = 0; i < a.size(); ++i)
		res += a[i];
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	
}