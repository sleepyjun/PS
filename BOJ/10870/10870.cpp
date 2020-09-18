#include <iostream>
#include <algorithm>

using std::cin; using std::cout;
typedef std::pair<int, int> pii;
const int INF = 987654321;

int fibo[21];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i = 2; i <= n; ++i)
		fibo[i] = fibo[i-1] + fibo[i-2];
	cout << fibo[n] << '\n';
}