#include<iostream>
#include<algorithm>
using namespace std;

int A[101][101];
int B[101][101];
int C[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m,k;
	
	cin >> n >> m;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			cin >> A[i][j];
	
	cin >> m >> k;
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=k; ++j)
			cin >> B[i][j];
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= k; ++j)
			for(int x = 1; x <= m; ++x)
				C[i][j] += A[i][x] * B[x][j];
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=k; ++j)
			cout << C[i][j] << ' ';
		cout << '\n';	
	}
	
}