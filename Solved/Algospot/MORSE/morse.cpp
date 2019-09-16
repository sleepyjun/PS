#include <iostream>
#include <algorithm>
#include <string>
using std::cin; using std::cout;

const int MAX = 1000000000+100;
int skip;
int bino[201][201];

void calcBino() 
{
	for(int i = 0; i <= 200; ++i)
	{
		bino[i][0] = bino[i][i] = 1;
		for(int j = 1; j < i; ++j)
			bino[i][j] = std::min(MAX, 
				bino[i-1][j-1] + bino[i-1][j]);
	}
}

std::string gen(int n, int m)
{
	if(n==0) return std::string(m, 'o');
	
	if(skip < bino[n-1+m][n-1])
		return "-"+gen(n-1,m);
	skip -= bino[n+m-1][n-1];
	return "o"+gen(n,m-1);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	calcBino();
	while(t--)
	{
		int n, m, k; cin >> n >> m >> k;
		skip = k-1;
		cout << gen(n,m) << '\n';
	}
}