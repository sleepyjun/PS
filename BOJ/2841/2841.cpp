#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <stack>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::stack<int> guitar[7]; //idx 0 is empty;
	int n, p; cin >> n >> p;
	
	int cnt = 0;
	for(int i = 1; i <= 6; ++i)
		guitar[i].push(-1);
	
	for(int i = 0; i < n; ++i)
	{
		int line, pret;
		cin >> line >> pret;
		
		while(guitar[line].top() > pret)
		{
			cnt++;
			guitar[line].pop();
		}
		
		if(guitar[line].top() < pret)
		{
			guitar[line].push(pret);
			cnt++;
		}
	}
	
	cout << cnt << '\n';
}