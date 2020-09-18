
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1000][1000];
int sumArr[1001][1001];

void init(int r, int c)
{
	for(int i = 0; i < r; ++i)
	{
		int iIdx = i+1;
		for(int j = 0; j < c; ++j)
		{
			int jIdx = j+1;
			sumArr[iIdx][jIdx] += sumArr[iIdx][j] +
				sumArr[i][jIdx] - sumArr[i][j] + arr[i][j];
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int r,c,q; cin >> r >> c >> q;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			cin >> arr[i][j];
	init(r,c);
	while(q--)
	{
		int r1,c1,r2,c2;
		cin >> r1 >> c1
			>> r2 >> c2;
		r1--; c1--;
		int cnt = (r1-r2)*(c1-c2);
		int res = sumArr[r2][c2] - sumArr[r2][c1]
			- sumArr[r1][c2] + sumArr[r1][c1];
		cout << res/cnt << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;