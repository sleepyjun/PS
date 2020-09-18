/*https://www.acmicpc.net/problem/2004*/
#include <iostream>
#include <algorithm>

using std::cin; using std::cout;

int count(int x, int pivot)
{
	int cnt = 0;
	for(long long i = pivot; x/i >= 1; i *= pivot)
		cnt += x/i;
	return cnt;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m; cin >> n >> m;
	
	int n5 = count(n,5);
	int n2 = count(n,2);
	
	int m5 = count(m,5);
	int m2 = count(m,2);
	int nm5 = count(n-m,5);
	int nm2 = count(n-m,2);
	
	n5 = n5 - m5 - nm5;
	n2 = n2 - m2 - nm2;
	
	cout << std::min(n5,n2) << '\n';
}