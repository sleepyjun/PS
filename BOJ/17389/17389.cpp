#include <iostream>
#include <algorithm>
#include <string>
using std::cin; using std::cout;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	std::string str; cin >> str;
	
	int sum = 0;
	int bonus = 0;
	for(int i = 0; i < n; ++i)
	{
		if(str[i] == 'O')
		{
			sum += (i + bonus + 1);
			bonus++;
		}
		else
		{
			bonus = 0;
		}
	}
	cout << sum << '\n';
}