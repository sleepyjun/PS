#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::cin; using std::cout;

std::stack<int> s;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::vector<int> v(n), ans(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	std::stack<int> s;
	for(int i = n-1; i >= 0; --i)
	{
		while(!s.empty() && s.top() <= v[i]) s.pop();
		
		if(s.empty() == true) ans[i] = -1;
		else ans[i] = s.top();
		s.push(v[i]);
	}
	
	for(int res : ans)
		cout << res << ' ';
	cout << '\n';
}