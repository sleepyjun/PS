#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<int> v;
	while(n)
	{
		v.push_back(n%10);
		n/=10;
	}
	
	
	sort(v.begin(), v.end(), std::greater<int>());
	for(int num : v)
		cout << num;
	cout << '\n';
}