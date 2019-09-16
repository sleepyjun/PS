#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int a[3];
	int c[3];
	//0=x 1=y 2=z
	for(int i = 0; i < 3; ++i)
		cin >> a[i];
	for(int i = 0; i < 3; ++i)
		cin >> c[i];
	// a 🍰 b = (a.z + b.x, a.y × b.y, a.x + b.z) == cx, cy, cz
	// cx = a.z + b.x
	  // bx = cx-az
	// cy = ay*by
	  // by = cy/ay
	// cz = ax+bz
	  // bz = cz-ax
	
	cout << c[0]-a[2] << ' ' << c[1]/a[1] << ' ' << c[2]-a[0] << endl;
}	