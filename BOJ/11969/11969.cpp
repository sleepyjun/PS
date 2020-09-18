// https://www.acmicpc.net/problem/11969
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
int sumArr[3][100001];

void init(int n)
{
	int j = 1;
	for(int i = 0; i < n; ++i, ++j)
	{
		switch(arr[i]) {
			case 1:
				sumArr[0][j] = 1;
				break;
			case 2:
				sumArr[1][j] = 1;
				break;
			case 3:
				sumArr[2][j] = 1;
				break;
		}
		for(int k = 0; k < 3; ++k)
			sumArr[k][j] += sumArr[k][j-1];
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
		int a,b; cin >> a >> b;
		for(int i = 0; i < 3; ++i)
			cout << sumArr[i][b] - sumArr[i][a-1] << ' ';
		cout << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;