#include <iostream>
#include <algorithm>
#include <cstdlib>
using std::cin; using std::cout;

int n,m;
char board[100][100];
bool judge[2];
char ans[100][100];
const char shape[2][2][5] = {
	{
		{"A  A"},
		{"AAAA"}
	},
	{
		{"BB  "},
		{"    "}
	}
	// {
	// 	{"ABBA"},
	// 	{"AAAA"}
	// }
};
bool modify(int x, int y, int type, int action)
	//fill action is 1, delete action is 0;
{
	if(action == 1)
	{
		for(int dy = 0; dy < 2; ++dy)
			for(int dx = 0; dx < 4; ++dx)
			{
				if(shape[type][dy][dx] == ' ')
					continue;
				if(x+dx >= m || y+dy >= n) return false;
				if(board[y+dy][x+dx] != 'X')
					return false;
			}
		for(int dy = 0; dy < 2; ++dy)
			for(int dx = 0; dx < 5; ++dx)
			{
				if(shape[type][dy][dx] != ' ' 
				   && board[y+dy][x+dx] == 'X')
					board[y+dy][x+dx] = shape[type][dy][dx];
			}

	}
	else
	{
		for(int dy = 0; dy < 2; ++dy)
			for(int dx = 0; dx < 5; ++dx)
			{
				if(board[y+dy][x+dx] == 'A' 
				   || board[y+dy][x+dx] == 'B')
					board[y+dy][x+dx] = 'X';
			}
	}	
	return true;
}
bool func()
{
	int ny = -1, nx = -1;
	bool flag = true;
	for(int y = 0; y < n && flag; ++y)
		for(int x = 0; x < m && flag; ++x)
		{
			if(board[y][x] == 'X')
			{
				ny = y;
				nx = x;
				flag = false;
			}
		}
	if(ny == -1) 
	{

			for(int y = 0; y < n; ++y)
			{
				for(int x = 0; x < m; ++x)
				{
					cout << board[y][x];
				}
				cout << '\n';
			}
		exit(0);
	}
	for(int type = 0; type < 2; ++type)
	{
		judge[type] = modify(nx, ny, type, 1);
		if(judge[type]) //if true is really changed
		{
			func();
			modify(nx, ny, type, 0);
		}
	}
	
	if(judge[0] == judge[1] && judge[0] == false)
		return false;
	else return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int y = 0; y < n; ++y)
		for(int x = 0; x < m; ++x)
			cin >> board[y][x];

	func();
 	cout << -1 << '\n';
}