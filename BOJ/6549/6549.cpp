#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = 987654321;

std::vector<ull> h;

ull solve(int n)
{
	ull res = 0;
	std::stack<ull> s;
	
	for(int i = 0; i < n; ++i)
	{
		while(!s.empty() && h[s.top()] > h[i])
		{
			ull height = h[s.top()];
			s.pop();
			ull width = i;
			if(!s.empty())
				width = i - s.top() - 1;
			res = std::max(res, height*width);
		}
		s.push(i);
	}
	
	while(!s.empty())
	{
		ull height = h[s.top()];
		s.pop();
		ull width = n;
		if(!s.empty())
			width = n - s.top() - 1;
		res = std::max(res, height*width);
	}
	return res;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		int n; cin >> n;
		if(n == 0) 
			break;
		
		h.clear();
		for(int i = 0; i < n; ++i)
		{
			int num; cin >> num;
			h.push_back(num);
		}
		
		cout << solve(n) << '\n';
	}
}