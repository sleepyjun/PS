#include <iostream>
#include <algorithm>

using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	cout << n*m-1 << '\n';
}