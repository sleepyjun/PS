// 
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const long long MOD = 1e9+7;
long long pow2(int n)
{
	long long res = 1;
	long long exp = 2;
	while(n)
	{
		if(n&1) res = (res*exp)%MOD;
		n>>=1;
		exp = (exp*exp)%MOD;
	}
	return res%MOD;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<long long> arr(n);
	for(int i = 0; i < n; ++i) cin >> arr[i];
	std::sort(arr.begin(), arr.end());
	long long res = 0;
	for(int i = 0; i < n; ++i)
		res = (res + (pow2(i) - pow2(n-i-1))*arr[i])%MOD;

	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp