// https://www.acmicpc.net/problem/10986
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

ull arr[1000001];
ull sumArr[1000001];
ull sameMOD[1000];
void init(const int n, const int MOD)
{
	for(int i = 0; i < n; ++i)
	{
		int idx = i+1;
		sumArr[idx] = (sumArr[i]+arr[i])%MOD;
		sameMOD[sumArr[idx]]++;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	init(n,m);
	ull cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(!(sumArr[i]%m)) cnt++;

	for(int i = m-1; i >= 0; --i)
		cnt += (sameMOD[i]*(sameMOD[i]-1)/2);
	cout << cnt << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;