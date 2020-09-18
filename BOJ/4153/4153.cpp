#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

int side[3];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		for(int i = 0; i < 3; ++i)
			cin >> side[i];
		if(side[0] == 0) break;
		
		std::sort(side, side+3);
		if(side[2]*side[2] == 
		   side[0]*side[0] + side[1]*side[1])
			cout << "right" << '\n';
		else 
			cout << "wrong" << '\n';	
	}
}