// https://www.acmicpc.net/problem/11997
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <unordered_set>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int arr[1001][1001];
int sumArr[1001][1001];

int func(int x1, int y1, int x2, int y2)
{
	// x1--; y1--;
	return sumArr[y2][x2] - sumArr[y2][x1] - sumArr[y1][x2] + sumArr[y1][x1];
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<int> data[2], xList, yList;
	for(int i = 0; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		xList.push_back(x);
		yList.push_back(y);
	}
	data[0].assign(xList.begin(), xList.end());
	data[1].assign(yList.begin(), yList.end());
	
	std::unordered_set<int> xSet(xList.begin(), xList.end());
	std::unordered_set<int> ySet(yList.begin(), yList.end());
	
	xList.clear(); yList.clear();
	
	xList.assign(xSet.begin(), xSet.end());
	yList.assign(ySet.begin(), ySet.end());
	
	std::sort(xList.begin(), xList.end());
	std::sort(yList.begin(), yList.end());
	
	int X = xList.size();
	int Y = yList.size();
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < X; ++j)
		{
			if(data[0][i] == xList[j])
			{
				data[0][i] = j;
				break;
			}
		}
		for(int j = 0; j < Y; ++j)
		{
			if(data[1][i] == yList[j])
			{
				data[1][i] = j;
				break;
			}
		}
	}
	
	for(int i = 0; i < n; ++i)
		arr[data[1][i]][data[0][i]]++;
	

	for(int i = 0; i < Y; ++i)
		for(int j = 0; j < X; ++j)
			sumArr[i+1][j+1] = arr[i][j] + sumArr[i][j+1] + sumArr[i+1][j] - sumArr[i][j];
	
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