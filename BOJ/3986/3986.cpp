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
	
	int t; cin >> t;
	int cnt = 0;
	while(t--)
	{
		std::string str;
		cin >> str;
		std::stack<char> s;
		
		for(int i = 0; i < str.length(); ++i)
		{
			if(s.empty() == true)
				s.push(str[i]);
			else if(s.top() == str[i])
				s.pop();
			else if(s.top() != str[i])
				s.push(str[i]);
		}
		
		if(s.empty() == true)
			cnt++;
	}
	cout << cnt << '\n';
}