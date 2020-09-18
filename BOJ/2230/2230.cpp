// https://www.acmicpc.net/problem/2230
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
	std::sort(arr,arr+n);
	int s=0,e=0,res=INF;
	while(1)
	{
		int diff = arr[e]-arr[s];
		if(s == n) break;
		else if(m > diff)
		{
			if(e < n-1) e++;
			else s++;
		}
		else
		{
			res = std::min(res, diff);
			s++;
		}
	}
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;