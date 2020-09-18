#include <iostream>
#include <algorithm>
#include <limits>
#include <stack>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

double num[26];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::string str; cin >> str;
	for(int i = 0; i < n; ++i)
		cin >> num[i];
	
	std::stack<double> calc;
	for(int i = 0; i < str.length(); ++i)
	{
		if('A' <= str[i] && str[i] <= 'Z')
			calc.push(num[str[i]-'A']);
		else
		{
			double b = calc.top(); calc.pop();
			double a = calc.top(); calc.pop();
			double res;
			if(str[i] == '+')
				res = a+b;
			else if(str[i] == '-')
				res = a-b;
			else if(str[i] == '*')
				res = a*b;
			else if(str[i] == '/')
				res = a/b;
			calc.push(res);
		}
	}
	cout.setf(std::ios::fixed);
	cout.precision(2);
	cout << calc.top() << '\n';
}