// https://www.acmicpc.net/problem/2003
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[10001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	int s=0, e=0, sum=0, cnt=0;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	while(1)
	{
		if(m <= sum) sum -= arr[s++];
		else if(e == n) break;
		else sum += arr[e++];
		if(sum == m) cnt++;
	}
	cout << cnt << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;