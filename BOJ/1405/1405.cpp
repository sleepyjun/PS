// https://www.acmicpc.net/problem/1405
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

const int dir[4][2] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

double EWSN[4];
std::set<pii> visited;
double func(int y, int x, int remain)
{
	if(visited.find({y,x}) != visited.end())
		return 0;
	if(remain == 0) 
		return 1;
	
	visited.insert({y,x});
	double res = 0;
	for(int i = 0; i < 4; ++i)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		res += (EWSN[i]/100)*func(ny,nx,remain-1);
	}
	visited.erase(visited.find({y,x}));
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < 4; ++i)
		cin >> EWSN[i];
	
	double res = 0;
	for(int i = 0; i < 4; ++i)
	{
		int ny = dir[i][0];
		int nx = dir[i][1];
		
		visited.clear();
		visited.insert({0,0});
		
		res += (EWSN[i]/100)*func(ny,nx,n-1);
	}
	cout << std::fixed; cout.precision(10);
	cout << res << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;