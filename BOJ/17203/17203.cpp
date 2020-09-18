// https://www.acmicpc.net/problem/17203
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1001];
int sumArr[1001];

void init(int n)
{
	int j = 2;
	for(int i = 0; i < n-1; ++i)
	{
		sumArr[j] = sumArr[j-1] + std::abs(arr[i]-arr[i+1]);
		j++;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,q; cin >> n >> q;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	init(n);
	
	while(q--)
	{
		int i,j; cin >> i >> j;
		if(j-1<i) cout << 0;
		else cout << sumArr[j] - sumArr[i];
		cout << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;