#include<iostream>
#include<string>
//#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string input;
	int res = 0;
	int cnt = 0;
	cin >> input;
	
	for(int i = 0; i < input.length(); ++i)
	{
		if(input[i] == '(')
		{
			if(input[i+1] == ')') //레이저
				res += cnt;
			else
				cnt++;
		}
		else if(input[i-1] == ')')
		{
			res += 1;
			cnt--;
		}
	}
	
	cout << res << '\n';
}