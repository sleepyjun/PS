#include <iostream>
#include <algorithm>
#include <limits>
using std::cin; using std::cout;

const long long NINF = std::numeric_limits<long long>::min();
int A[100];
int B[100];
int dp[101][101];
int n,m; 
int func(int idxA, int idxB)
{
	int& ret = dp[idxA+1][idxB+1];
	if(ret != -1) return ret;
	ret = 2;
	long long a = (idxA == -1 ? NINF : A[idxA]);
	long long b = (idxB == -1 ? NINF : B[idxB]);
	long long maxElement = std::max(a,b);
	
	for(int nextA = idxA + 1; nextA < n; ++nextA)
	{
		if(maxElement < A[nextA])
			ret = std::max(ret, func(nextA, idxB)+1);
	}
	for(int nextB = idxB + 1; nextB < m; ++nextB)
	{
		if(maxElement < B[nextB])
			ret = std::max(ret, func(idxA, nextB)+1);
	}
	
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> m;
		std::fill(A, A+100, 0);
		std::fill(B, B+100, 0);
		std::fill(&dp[0][0], &dp[101][101], -1);
		
		for(int i = 0; i < n; ++i)
			cin >> A[i];
		for(int i = 0; i < m; ++i)
			cin >> B[i];
		
		cout << func(-1,-1)-2 << '\n';
	}
}