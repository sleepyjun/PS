#include <iostream>
#include <algorithm>
using namespace std;

const int BLOCKS[4][3][2] = {
	{{0,0},{0,1},{1,1}},
	{{0,0},{0,1},{-1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{0,1}}
};//(x,y)
int res = 0;
int h,w;
int board[20][20];
//true is block, false is empty

bool judge(int x, int y, int type, int alpha)
{
	bool flag = true;
	for(int i = 0; i < 3; ++i)
	{
		int nx = x + BLOCKS[type][i][0];
		int ny = y + BLOCKS[type][i][1];
		if(nx < 0 || nx >= w || ny < 0 || ny >= h)
			flag = false;
		else if((board[ny][nx]+=alpha) > 1)
			flag = false;
	}
	
	return flag;
}
void func()
{
	bool flag = true;
	int cx, cy;
	for(int y = 0; y < h && flag; ++y)
			for(int x = 0; x < w && flag; ++x)
			{
				if(board[y][x] == false)
				{
					cx = x;
					cy = y;
					flag = false;
				}
			}
	
	if(flag) {res += 1; return;}
	
	for(int type = 0; type < 4; ++type)
	{
		if(judge(cx,cy,type,1))
		{
			func();
		}
		judge(cx,cy,type,-1);
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	int cnt;
	while(t--)
	{
		cin >> h >> w;
		/*=================================*/
		cnt = 0; res = 0;
		for(int y = 0; y < 20; ++y)
			for(int x = 0; x < 20; ++x)
				board[y][x] = 0;
		/*=================================*/
		for(int y = 0; y < h; ++y)
			for(int x = 0; x < w; ++x)
			{
				char ch; cin >> ch;
				if(ch == '#') board[y][x] = 1;
				else cnt++;
			}
		
		if(cnt % 3 == 0) func();
		cout << res << endl;
	}
}