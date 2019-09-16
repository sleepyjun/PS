#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const string DEATH = "666";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cnt = 1;
	int n;
	cin >> n;
	for(int i = 666; ; i++)
		if(to_string(i).find(DEATH) != -1 && n == cnt)
		{	
			cout << i << '\n';
			break;
		}
		else if(to_string(i).find(DEATH) != -1)
			cnt++;
}