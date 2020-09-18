#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using std::cin; using std::cout;

std::string solve(const std::string& str)
{
	std::stack<char> s;
	const std::string start("({[");
	const std::string end(")}]");
	
	for(int i = 0; i < str.length(); ++i)
	{
		if(start.find(str[i]) != -1)
			s.push(str[i]);
		else
		{
			if(s.empty() == true) return "NO";
			if(start.find(s.top()) != end.find(str[i]))
				return "NO";
			s.pop();
		}
	}
	if(s.empty() == true) return "YES";
	return "NO";
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	
	
	
	while(t--)
	{
		std::string str; cin >> str;
		
		cout << solve(str) << '\n';
	}
}