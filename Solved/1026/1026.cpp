#include <iostream>
#include <algorithm>
#include <functional>
using std::cin; using std::cout;

int A[51];
int B[51];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	for(int i = 0; i < n; ++i)
		cin >> B[i];
	
	std::sort(A, A+n);
	std::sort(B, B+n, std::greater<int>());
	
	int res = 0;
	for(int i = 0; i < n; ++i)
		res += A[i]*B[i];
	
	cout << res << '\n';
}