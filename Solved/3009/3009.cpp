#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x,y; cin >> x >> y; 	
	int resX = x, resY = y;
	
	cin >> x >> y;
	if(resX == x)
	{
		cin >> x;
		resX = x;
	}
	else
	{
		resX += x;
		cin >> x;
		resX -= x;
	}
	
	if(resY == y)
	{
		cin >> y;
		resY = y;
	}
	else
	{
		resY += y;
		cin >> y;
		resY -= y;
	}
	cout << resX << ' ' << resY << '\n';
}