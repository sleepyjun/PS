#include <iostream>
#include <algorithm>
using std::cin; using std::cout;

const int MAX = 10000001;
int factors[MAX];
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 1; i < MAX; ++i)
		for(int j = i; j < MAX; j+=i)
			factors[j] += 1;
	
	int t; cin >> t;
	while(t--)
	{
		int cnt, lo, hi; cin >> cnt >> lo >> hi;
		int res = 0;
		for(int i = lo; i <= hi; ++i)
			if(factors[i] == cnt)
				res++;
		cout << res << '\n';
	}
}
	