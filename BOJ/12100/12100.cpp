// https://www.acmicpc.net/problem/12100
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n;

void fillSpace(int board[21][21])
{
	for(int y = 1; y <= n; ++y)
	{
		for(int x = 1; x <= n; ++x)
		{
			if(board[y][x] == 0)
			{
				for(int i = y+1; i <= n; ++i)
					if(board[i][x] != 0)
					{
						board[y][x] = board[i][x];
						board[i][x] = 0;
						break;
					}
			}
		}
	}
}
void update(int board[21][21])
{
	for(int y = 2; y <= n; ++y)
	{
		for(int x = 1; x <= n; ++x)
		{
			if(board[y-1][x] && board[y-1][x] == board[y][x])
			{
				board[y-1][x] += board[y][x];
				board[y][x] = 0;
			}
		}
	}
}

void rotate(int board[21][21])
{
	int tempBoard[21][21];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			tempBoard[i][j] = board[n-j+1][i];
	std::copy(&tempBoard[0][0],&tempBoard[0][0]+21*21, &board[0][0]);
}
void move(int board[21][21], int dir)
{
	switch(dir) {
		case 0:
			for(int i = 0; i < 3; ++i) rotate(board);
			break;
		case 1:
			for(int i = 0; i < 1; ++i) rotate(board);
			break;
		case 2:
			for(int i = 0; i < 2; ++i) rotate(board);
			break;
	}
	fillSpace(board);
	update(board);
	fillSpace(board);
	switch(dir) {
		case 0:
			for(int i = 0; i < 1; ++i) rotate(board);
			break;
		case 1:
			for(int i = 0; i < 3; ++i) rotate(board);
			break;
		case 2:
			for(int i = 0; i < 2; ++i) rotate(board);
			break;
	}
	
}

int calc(int board[21][21])
{
	int max = -1;
	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= n; ++x)
			max = std::max(max, board[y][x]);
	return max;
}
int func(int board[21][21], int cnt = 0)
{
	int max = calc(board);
	if(cnt == 5) 
		return max;
	
	for(int i = 0; i < 4; ++i)
	{
		int tempBoard[21][21];
		std::copy(&board[0][0],&board[0][0]+21*21,&tempBoard[0][0]);
		
		move(tempBoard,i);
		max = std::max(max,func(tempBoard, cnt+1));
	}
	return max;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	int board[21][21];
	for(int y = 1; y <= n; ++y)
		for(int x = 1; x <= n; ++x)
			cin >> board[y][x];
			
	cout << func(board) << '\n';
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;