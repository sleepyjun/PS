#include <iostream>
#include <algorithm>
using namespace std;

const int PACKAGE = 6;
const int THING = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M; cin >> N >> M;
	int sum = 0;
	int minPackage = 999999;
	int minThing = 999999;
	
	for(int i = 1; i <= M; ++i)
	{
		int package, thing;
		cin >> package >> thing;
		minPackage = min(minPackage, package);
		minThing = min(minThing, thing);
	}
	
	while(N)
	{
		if(N>=6)
		{
			int cnt = N / PACKAGE;
			N -= cnt*PACKAGE;
			sum += min(cnt*minPackage, cnt*PACKAGE*minThing);
		}
		else
		{
			sum += min(minPackage, minThing*N);
			N = 0;
		}
	}
	
	cout << sum << endl;
}