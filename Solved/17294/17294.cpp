#include <iostream>
#include <algorithm>
#include <string>
using std::cin; using std::cout;

bool func(const std::string& str)
{
	for(int i = 1; i < str.length(); ++i)
	{
		if(str[i]-str[i-1] != str[1]-str[0])
			return false;
	}
	return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::string str; cin >> str;
	if(func(str))
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << '\n';
	else
		cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << '\n';
}