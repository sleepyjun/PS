// https://www.acmicpc.net/problem/11997
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1001][2];
int map[1001][1001];
int sumArr[1001][1001];

int func(int x1, int y1, int x2, int y2)
{
	// x1--; y1--;
	return sumArr[y2][x2] - sumArr[y2][x1] - sumArr[y1][x2] + sumArr[y1][x1];
}

int getIdx(const std::vector<int>& idx, int x)
{
	return std::lower_bound(idx.begin(), idx.end(), x)
		- idx.begin();
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<int> xIdx, yIdx;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i][0] >> arr[i][1];
		xIdx.push_back(arr[i][0]);
		yIdx.push_back(arr[i][1]);
	}
	std::sort(xIdx.begin(), xIdx.end());
	xIdx.erase(std::unique(xIdx.begin(), xIdx.end()),
			xIdx.end());
	
	std::sort(yIdx.begin(), yIdx.end());
	yIdx.erase(std::unique(yIdx.begin(), yIdx.end()),
			yIdx.end());
	
	int X = xIdx.size();
	int Y = yIdx.size();
	
	for(int i = 0; i < n; ++i)
	{
		int x = getIdx(xIdx, arr[i][0]);
		int y = getIdx(yIdx, arr[i][1]);
		map[y][x]++;
	}
	
	for(int i = 0; i < Y; ++i)
		for(int j = 0; j < X; ++j)
			sumArr[i+1][j+1] = map[i][j] + sumArr[i+1][j] + sumArr[i][j+1] - sumArr[i][j];
	
	int res = INF;
	for(int i = 0; i < Y; ++i)
	{
		for(int j = 0; j < X; ++j)
		{
			int temp = std::max(func(0,0,j,i), func(j,i,X,Y));
			temp = std::max(func(j,0,X,i), temp);
			temp = std::max(func(0,i,j,Y), temp);
			
			res = std::min(res, temp);
		}
	}
	
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;