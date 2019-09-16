#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while(t--)
	{
		int tmp, num = 0;
		deque<int> dq;
		string str, numStr;
		bool forward = true, error = false;
		
		cin >> str;
		cin >> tmp; tmp = 10;
		cin >> numStr;
		//input num
		for(int i = 1; i < numStr.size(); ++i)
		{
			
			if('0' <= numStr[i] && numStr[i] <= '9')
			{
				num *= tmp;
				num += numStr[i] - '0';
			}
			else
			{
				if(num) dq.push_back(num);
				num = 0; tmp = 10;
			}
		}

		//func
		for(int i = 0; i < str.length(); ++i)
		{
			if(str[i] == 'R') forward = !forward;
			else if(str[i] == 'D')
			{
				if(dq.empty())
				{
					error = true;
					break;
				}
					
				if(forward == true)
					dq.pop_front();
				else if(forward == false)
					dq.pop_back();
			}
		}
		
		if(!dq.empty() && forward == true)
		{
			cout << '[';
			for(int i = 0; i < dq.size(); ++i)
			{
				if(i == dq.size()-1)
					cout << dq.at(i);
				else cout << dq.at(i) << ',';
			}
			cout << ']' << '\n';
		}
		else if(!dq.empty() && forward == false)
		{
			cout << '[';
			for(int i = dq.size()-1; i >= 0; --i)
			{
				if(i == 0)
					cout << dq.at(i);
				else cout << dq.at(i) << ',';
			}
			cout << ']' << '\n';
		}
		else if(error == true)
			cout << "error\n";
		else if(error == false)
			cout << "[]\n";
	}
}