//https://www.acmicpc.net/problem/11758
#include <iostream>
using namespace std;

int P[3][2];
//0 is X, 1 is Y
int ccw()
{
	int temp = P[0][0]*P[1][1]+P[1][0]*P[2][1]+P[2][0]*P[0][1];
	temp -= P[0][1]*P[1][0]+P[1][1]*P[2][0]+P[2][1]*P[0][0];
	if(temp > 0)
		return 1;
	else if(temp < 0)
		return -1;
	else return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 0; i < 3; ++i)
		cin >> P[i][0] >> P[i][1];
	
	cout << ccw() << '\n';
}