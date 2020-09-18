// https://www.acmicpc.net/problem/14499
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

enum DIR{EAST=1, WEST, NORTH, SOUTH};
const int SPIN[5][6] = {
//0:floor, 1:east,  2:west
//3:north, 4:south, 5:ceil
	{0,0,0,0,0,0},
	{1,5,0,3,4,2},
	{2,0,5,3,4,1},
	{3,1,2,5,0,4},
	{4,1,2,0,5,3}
};
int dice[6];
int map[21][21];
int n,m; //n is vertical // m is horizon

bool chkCoord(const int order,
	const int cy, const int cx)
{
	switch(order) {
		case EAST:
			if(cx+1 > m-1) return false;
			break;
		case WEST:
			if(cx-1 < 0) return false;
			break;
		case NORTH:
			if(cy-1 < 0) return false;
			break;
		case SOUTH:
			if(cy+1 > n-1) return false;
			break;
	}
	return true;
}
void updateDice(const int order)
{
	int dest[6];
	for(int i = 0; i < 6; ++i)
		dest[i] = dice[SPIN[order][i]];
	std::copy(dest,dest+6,dice);
}
void updateMap(const int y, const int x)
{
	if(map[y][x] == 0)
		map[y][x] = dice[0];
	else
	{
		dice[0] = map[y][x];
		map[y][x] = 0;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	int cx,cy; cin >> cy >> cx;
	int k; cin >> k;
	
	for(int y = 0; y < n; ++y) //y
		for(int x = 0; x < m; ++x) //x
			cin >> map[y][x];
	
	while(k--)
	{
		int order; cin >> order;
		if(false == chkCoord(order,cy,cx)) continue;
		switch(order) {
			case EAST:
				cx += 1;
				break;
			case WEST:
				cx -= 1;
				break;
			case NORTH:
				cy -= 1;
				break;
			case SOUTH:
				cy += 1;
				break;
		}
		updateDice(order);
		updateMap(cy,cx);
		cout << dice[5] << '\n';
	}
}