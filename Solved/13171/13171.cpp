#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const ull MOD = 1000000007;
ull src[80];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ull A, X; cin >> A >> X;
	int cnt = 1;
	src[cnt++] = A%MOD;
	for(ull i = X; i != 1; i /= 2)
	{
		src[cnt] = ((src[cnt-1] % MOD)*(src[cnt-1] % MOD)) % MOD;
		cnt++;
	}

	ull res = 1;		
	cnt = 1;
	while(X)
	{
		ull comp = 1;

		
		if((X & comp))
		{
			res = ((res % MOD)*(src[cnt] % MOD)) % MOD;
		}
		cnt++;
		X = X >> 1;
	}
	
	cout << res << endl;
}