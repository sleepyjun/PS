#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <stack>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::string str;
	cin >> str;
	std::stack<char> s;
	std::stack<int> si;
	std::string temp;
	
	for(int i = 0; i < str.length(); ++i)
	{	
		if('0' <= str[i] && str[i] <= '9')
		{
			while('0' <= str[i] && str[i] <= '9')
			{
				temp += str[i++];
			}
			temp += ' ';
		}
		if(str[i] == '+' || str[i] == '-')
		{
			while(!s.empty() && ((str[i] == '-' && s.top() == '+') || (str[i] == s.top())))
			{
				temp += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while(!s.empty())
	{
		temp += s.top();
		s.pop();
	}
	
	for(int i = 0; i < temp.length(); ++i)
	{
		if('0' <= temp[i] && temp[i] <= '9')
		{
			int x = 0;
			while('0' <= temp[i] && temp[i] <= '9')
			{
				x = x*10 + (temp[i++]-'0');
			}
			si.push(x);
		}
		
		if(temp[i] == '+')
		{
			int a = si.top();
			si.pop();
			int b = si.top();
			si.pop();
			si.push(b+a);
		}
		else if(temp[i] == '-')
		{
			int a = si.top();
			si.pop();
			int b = si.top();
			si.pop();
			si.push(b-a);
		}
	}
	
	cout << si.top() << '\n';
}