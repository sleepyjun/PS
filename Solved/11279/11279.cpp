#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::priority_queue<int> pq;
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		
		if(x==0 && pq.empty()) cout << '0' << '\n';
		else if(x==0)
		{
			cout << pq.top() << '\n'; pq.pop();
		}
		else
		{
			pq.push(x);
		}
		
	}
}