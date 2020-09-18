// https://www.acmicpc.net/problem/1806
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int arr[100001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	int res=INF,len=0,sum=0,s=0,e=0;
	while(1)
	{
		if(sum >= m)
		{
			res = std::min(res,len);
			sum -= arr[s++];
			len--;
		}
		else if(n == e) break;
		else
		{
			sum += arr[e++];
			len++;
		}
	}
	cout << (res==INF ? 0 : res) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;