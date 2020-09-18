#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<unsigned long long> A, B;
	A.reserve(n); B.reserve(n);
	
	for(int i = 0; i < n; ++i)
	{
		unsigned long long temp; cin >> temp;
		A.push_back(temp);
	}
	for(int i = 0; i < n; ++i)
	{
		unsigned long long temp; cin >> temp;
		B.push_back(temp);
	}
	
	for(int i = 0; i < n; ++i)
	{
		std::vector<unsigned long long>::iterator up;
		up = std::upper_bound(B.begin(), B.end(), A[i]);
		unsigned long long pos = up-B.begin();
		
		cout << pos - i - 1;
		if(i == n-1) cout << '\n';
		else cout << ' ';
	}
	
}