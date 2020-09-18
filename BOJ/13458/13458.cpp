#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

long long a[1000001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	long long n,b,c; cin >> n;
	for(long long i = 0; i < n; ++i)
		cin >> a[i];
	cin >> b >> c;
	
	long long res = n;
	for(long long i = 0; i < n; ++i) {
		long long temp = a[i]-b;
		if(temp <= 0) continue;
		res += (temp/c + ((temp%c == 0) ? 0 : 1));
		
	}
	
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;