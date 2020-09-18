// https://www.acmicpc.net/problem/11660
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1024][1024];
int sumArr[1025][1025];
void init(const int n)
{
	for(int i = 0; i < n; ++i)
	{
		int iIdx = i+1;
		for(int j = 0; j < n; ++j)
		{
			int jIdx = j+1;
			sumArr[iIdx][jIdx] += arr[i][j] + 
				sumArr[i][jIdx] + sumArr[iIdx][j] -
				sumArr[i][j];
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> arr[i][j];
	init(n);
	while(m--)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 
			>> x2 >> y2;
		x1--; y1--;
		cout << sumArr[x2][y2] + sumArr[x1][y1]
			- sumArr[x1][y2] - sumArr[x2][y1] << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;