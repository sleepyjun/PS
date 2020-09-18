#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cin; using std::cout;

int S[21][21];
int C[21][21];
int n; 

void preCalc(int n)
{
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i <= n; ++i)
	{
		C[i][0] = 1;
		for(int j = 1; j <= n; ++j)
			C[i][j] = C[i-1][j-1]+C[i-1][j];
	}

}
int calc(const std::vector<int>& v, bool flag)
{
	int sum = 0;
	
	for(int i = 1; i <= n; ++i)
	{
		if(v[i] == flag)
		{
			for(int j = 1; j <= n; ++j)
				if(v[j] == flag)
					sum += S[i][j];
		}
	}

	return sum;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> S[i][j];
	
	preCalc(n);
	int count = C[n][n/2]/2;
	std::vector<int> v(n+1, 1);
	for(int i = 1; i <= n/2; ++i)
		v[i] = 0;
	
	int res = 987654321;
	do{
		res = std::min(res, 
					   abs(calc(v, true)-calc(v ,false)));
	}while(--count && 
		   std::next_permutation(v.begin()+1, v.end()));
	cout << res << '\n';
}