#include <iostream>
#include <algorithm>
#include <vector>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<int> nVec(n);
	for(int i = 0; i < n; ++i) cin >> nVec[i];
	
	int m; cin >> m;
	std::vector<int> mVec(m);
	for(int i = 0; i < m; ++i) cin >> mVec[i];
	
	std::sort(nVec.begin(), nVec.end());
	for(int i = 0; i < m; ++i)
	{
		auto low = 
			std::lower_bound(nVec.begin(),nVec.end(),mVec[i]);
		auto up = 
			std::upper_bound(nVec.begin(),nVec.end(),mVec[i]);
		
		cout << up-low << ' ';
	}
}