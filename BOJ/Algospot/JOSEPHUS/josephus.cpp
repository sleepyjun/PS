#include <iostream>
#include <algorithm>
#include <list>

using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n,k; cin >> n >> k;
		std::list<int> l;
		//already first soldier dead
		for(int i = 1; i <= n; ++i)
			l.push_back(i);
		
		std::list<int>::iterator it = l.begin();
		while(l.size() != 2)
		{
			it = l.erase(it);
			if(it == l.end()) it = l.begin();
			for(int i = 0; i < k-1; ++i)
			{
				++it;
				if(it == l.end()) it = l.begin();
			}
		}
		
		cout << l.front() << ' ' << l.back() << '\n';
	}
}