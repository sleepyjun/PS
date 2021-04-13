// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <deque>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

using pic = std::pair<int, char>;
enum { WALL=-1, EMPTY, SNAKE, APPLE };
const int DIR[4][2] = {
	{0,1},
	{-1,0},
	{0,-1},
	{1,0}
};
int board[105][105];

void init(int n)
{
	std::fill(&board[0][0], &board[104][105], WALL);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) 
			board[i][j] = EMPTY;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n; init(n);
	int k; cin >> k;
	for(int i = 0; i < k; ++i)
	{
		int y,x; cin >> y >> x;
		board[y][x] = APPLE;
	}
	int l; cin >> l;
	std::queue<pic> dir;
	for(int i = 0; i < l; ++i)
	{
		int x; 
		char c;
		cin >> x >> c;
		dir.push(std::make_pair(x,c));
	}
	
	std::deque<pii> snake;
	snake.push_back({1,1});
	board[1][1] = SNAKE;

	int res = 1;
	int head = 0;
	while(1)
	{
		int ny = snake.front().first + DIR[head][0];
		int nx = snake.front().second + DIR[head][1];

		if(board[ny][nx] == WALL || board[ny][nx] == SNAKE) break;
		if(board[ny][nx] == EMPTY)
		{
			int ty = snake.back().first;
			int tx = snake.back().second;
			board[ty][tx] = EMPTY;
			snake.pop_back();
		}
		snake.push_front({ny,nx});
		board[ny][nx] = SNAKE;

		if(!dir.empty() && res == dir.front().first)
		{
			if(dir.front().second == 'L') head = ((head == 3) ? 0 : head+1);
			else head = ((head == 0) ? 3 : head-1);
			dir.pop();
		}
		res++;
	}

	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp