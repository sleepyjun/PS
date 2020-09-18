// https://www.acmicpc.net/problem/13460
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

enum {EAST=0, WEST, SOUTH, NORTH};
enum RESULTCODE {NOTMOVED = -1, MOVED=0, REDBALLOUT, BLUEBALLOUT};
int N,M;
char BOARD[11][11];
pii INIT[3];

bool ballExist(int y, int x, int ry, int rx, int by, int bx)
{
	return ((y==ry)&&(x==rx) || (y==by)&&(x==bx));
}
RESULTCODE move(int dir,int& ry, int& rx, int& by, int& bx)
{
	RESULTCODE code = NOTMOVED;
	if(dir == EAST)
	{
		for(int x = M-1; x >= 0; --x)
			for(int y = 0; y < N; ++y)
				if(BOARD[y][x] == 'O')
					for(int i = x-1; i >= 0; --i)
					{
						if(BOARD[y][i] == '#') break;
						if(ry == y && rx == i)
							code = REDBALLOUT;
						if(by == y && bx == i)
							return code = BLUEBALLOUT;
					}
				else if(BOARD[y][x] == '.' && !ballExist(y,x,ry,rx,by,bx))
					for(int i = x-1; i >= 0; --i)
					{
						if(BOARD[y][i] != '.') break;
						if(ry == y && rx == i)
						{
							rx = x;
							code = std::max(code,MOVED);
							break;
						}
						if(by == y && bx == i)
						{
							bx = x;
							code = std::max(code,MOVED);
							break;
						}
					}
	}
	else if(dir == WEST)
	{
		for(int x = 0; x < M; ++x)
			for(int y = 0; y < N; ++y)
				if(BOARD[y][x] == 'O')
					for(int i = x+1; i < M; ++i)
					{
						if(BOARD[y][i] == '#') break;
						if(ry == y && rx == i)
							code = REDBALLOUT;
						if(by == y && bx == i)
							return code = BLUEBALLOUT;
					}
				else if(BOARD[y][x] == '.' && !ballExist(y,x,ry,rx,by,bx))
					for(int i = x+1; i < M; ++i)
					{
						if(BOARD[y][i] != '.') break;
						if(ry == y && rx == i)
						{
							rx = x;
							code = std::max(code,MOVED);
							break;
						}
						if(by == y && bx == i)
						{
							bx = x;
							code = std::max(code,MOVED);
							break;
						}
					}
	}
	else if(dir == SOUTH)
	{
		for(int y = N-1; y >= 0; --y)
			for(int x = 0; x < M; ++x)
				if(BOARD[y][x] == 'O')
					for(int i = y-1; i >= 0; --i)
					{
						if(BOARD[i][x] == '#') break;
						if(ry == i && rx == x)
							code = REDBALLOUT;
						if(by == i && bx == x)
							return code = BLUEBALLOUT;
					}
				else if(BOARD[y][x] == '.' && !ballExist(y,x,ry,rx,by,bx))
					for(int i = y-1; i >= 0; --i)
					{
						if(BOARD[i][x] != '.') break;
						if(ry == i && rx == x)
						{
							ry = y;
							code = std::max(code,MOVED);
							break;
						}
						if(by == i && bx == x)
						{
							by = y;
							code = std::max(code,MOVED);
							break;
						}
					}
	}
	else if(dir == NORTH)
	{
		for(int y = 0; y < N; ++y)
			for(int x = 0; x < M; ++x)
				if(BOARD[y][x] == 'O')
					for(int i = y+1; i < N; ++i)
					{
						if(BOARD[i][x] == '#') break;
						if(ry == i && rx == x)
							code = REDBALLOUT;
						if(by == i && bx == x)
							return code = BLUEBALLOUT;
					}
				else if(BOARD[y][x] == '.' && !ballExist(y,x,ry,rx,by,bx))
					for(int i = y+1; i < N; ++i)
					{
						if(BOARD[i][x] != '.') break;
						if(ry == i && rx == x)
						{
							ry = y;
							code = std::max(code,MOVED);
							break;
						}
						if(by == i && bx == x)
						{
							by = y;
							code = std::max(code,MOVED);
							break;
						}
					}
	}
	return code;
}
void bfs()
{
	int limit = 10;
	bool flag = true;
	std::queue<pii> redBallq, blueBallq;
	redBallq.push(INIT[0]);
	blueBallq.push(INIT[1]);
	while(!redBallq.empty() && limit > 0 && flag)
	{
		limit--;
		int qSize = redBallq.size();
		for(int i = 0; flag && i < qSize; ++i)
		{
			auto redBall = redBallq.front(); redBallq.pop();
			auto blueBall = blueBallq.front(); blueBallq.pop();
			
			int ry = redBall.first, rx = redBall.second;
			int by = blueBall.first, bx = blueBall.second;
			for(int dir = 0; flag && dir < 4; ++dir)
			{
				int nry = ry, nrx = rx;
				int nby = by, nbx = bx;
				RESULTCODE code = move(dir,nry,nrx,nby,nbx);
				if(code == REDBALLOUT) flag = false;
				else if(code == MOVED)
				{
					redBallq.push({nry,nrx});
					blueBallq.push({nby,nbx});
				}
			}
		}
	}
	if(flag) cout << -1 << '\n';
	else cout << 10 - limit << '\n';
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M; //y,x
	for(int y = 0; y < N; ++y)
	{
		for(int x = 0; x < M; ++x)
		{
			cin >> BOARD[y][x];
			if(BOARD[y][x] == 'R')
			{
				BOARD[y][x] = '.';
				INIT[0].first = y;
				INIT[0].second = x;
			}
			else if(BOARD[y][x] == 'B')
			{
				BOARD[y][x] = '.';
				INIT[1].first = y;
				INIT[1].second = x;
			}
			else if(BOARD[y][x] == 'O')
			{
				INIT[2].first = y;
				INIT[2].second = x;
			}
		}
	}
	
	bfs();
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;