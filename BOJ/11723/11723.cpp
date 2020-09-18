#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int set = 0;
	int n; cin >> n;
	while(n--)
	{
		std::string str;
		cin >> str;
		if(str == "add")
		{
			int x;
			cin >> x;
			int src = 1;
			
			src = (src << (x-1));
			set |= src;
		}
		else if(str == "remove")
		{
			int x;
			cin >> x;
			int src = 1;
			
			src = (src << (x-1));
			set &= ~(src);
		}
		else if(str == "check")
		{
			int x;
			cin >> x;
			int src = 1;
			
			src = (src << (x-1));
			if(set & (src))
				cout << 1 << '\n';
			else 
				cout << 0 << '\n';
		}
		else if(str == "toggle")
		{
			int x;
			cin >> x;
			int src = 1;
			
			src = (src << (x-1));
			set ^= src;
		}
		else if(str == "all")
		{
			set = 0xfffff;
		}
		else if(str == "empty")
		{
			set = 0;
		}
		else return 0;
	}
}