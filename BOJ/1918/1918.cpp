#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using std::cin; using std::cout;

int priority(char ch)
{
	switch(ch)
	{
		case '(':
		case ')':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return -1;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::string str; cin >> str;
	std::stack<char> s;
	
	for(int i = 0; i < str.length(); ++i)
	{
		int pri = priority(str[i]);
		if(pri == -1)
			cout << str[i];
		else 
		{
			if(str[i] == '(')
				s.push(str[i]);
			else if(str[i] == ')')
			{
				while(s.top() != '(')
				{
					cout << s.top();
					s.pop();
				}
				s.pop();
			}
			else if(pri >= 1)
			{
				while(!s.empty() && pri <= priority(s.top()))
				{
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			}
		}
	}
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << '\n';
}