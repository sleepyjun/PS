// https://www.acmicpc.net/problem/11441
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[100001];
long long pSum[100001];
int n, m;
void init()
{
	pSum[1] = arr[1];
	for(int i = 2; i <= n; ++i)
	{
		pSum[i] = pSum[i-1]+arr[i];
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> arr[i];
	init();
	cin >> m;
	while(m--)
	{
		int x,y; cin >> x >> y;
		cout << pSum[y]-pSum[x-1] << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;