#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	stack<char> s;
	string str;

	getline(cin, str);
	while(str.compare(".") != 0)
	{
		s = stack<char>();
		bool flag = true;	
		
		for(int i = 0; i < str.length()-1 && flag; ++i)
		{
			if(str[i] == '(')
				s.push('(');
			else if(str[i] == ')')
			{
				if(s.empty()) flag = false;
				else if(s.top() == '(')
					s.pop();
				else flag = false;
			}
			else if(str[i] == '[')
				s.push('[');
			else if(str[i] == ']')
			{
				if(s.empty()) flag = false;
				else if(s.top() == '[')
					s.pop();
				else flag = false;
			}
		}
		
		if(flag && s.empty()) cout << "yes\n";
		else cout << "no\n";
		getline(cin, str);
	}
}