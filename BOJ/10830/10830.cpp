#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

typedef unsigned long long ull;

const ull MOD = 1000; 
ull matrix[6][6];
ull res[6][6];
ull temp[6][6];
int n;
//idx will be start from 1

void mul(ull dest[6][6], ull src[6][6])
{
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			temp[i][j] = 0;
			for(int k = 1; k <= n; ++k)
				temp[i][j] += (dest[i][k] * src[k][j]);
			temp[i][j] %= MOD;
		}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dest[i][j] = temp[i][j];
}
void func(ull b)
{
	while(b)
	{
		if(b&1) mul(res, matrix);
		mul(matrix, matrix);
		b>>=1;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	ull b; cin >> b;
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cin >> matrix[i][j];
		res[i][i] = 1;
	}
	
	func(b);
		
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cout << res[i][j]%MOD << ' ';
		cout << '\n';
	}
}