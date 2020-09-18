// https://www.acmicpc.net/problem/17136
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

const int MAX = 10;
int board[MAX][MAX];
bool visited[MAX][MAX];
int remain[6] = {0,5,5,5,5,5};
int min = INF;

bool judge(int y, int x, int pic) 
{
	if(remain[pic] == 0 || y+pic > MAX || x+pic > MAX) return false;
	for(int i = y; i < y+pic; ++i)
	{
		for(int j = x; j < x+pic; ++j)
		{
			if(board[i][j] == 1 && visited[i][j] == false)
				continue;
			else return false;
		}
	}
	return true;
}
void marking(int y, int x, int pic, bool mark)
{
	for(int i = y; i < y+pic; ++i)
		for(int j = x; j < x+pic; ++j)
			visited[i][j] = (mark == true ? true : false);
	remain[pic] = remain[pic] + (mark == true ? -1 : 1);
}
void func(int y, int x, int cnt)
{
	if(cnt >= min) return;
	
	if(x == MAX)
	{
		func(y+1,0,cnt);
		return;
	}
	if(y == MAX)
	{
		bool flag = true;
		for(int y = 0; y < MAX; ++y)
			for(int x = 0; x < MAX; ++x)
				if(visited[y][x] == false) flag = false;
		if(flag)
			min = std::min(min, cnt);
		return;
	}
	if(visited[y][x] == true)
	{
		func(y,x+1,cnt);
		return;
	}
	
	for(int pic = 5; pic > 0; --pic)
	{
		if(judge(y,x,pic))
		{
			marking(y,x,pic,true);
			func(y,x+pic,cnt+1);
			marking(y,x,pic,false);
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 0; i < MAX; ++i)
	{
		for(int j = 0; j < MAX; ++j)
		{
			cin >> board[i][j];
			if(board[i][j] == 0) visited[i][j] = true;
		}
	}
	func(0,0,0);
	cout << (min == INF ? -1 : min) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;