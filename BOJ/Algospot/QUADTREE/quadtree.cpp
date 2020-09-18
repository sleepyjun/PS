#include <iostream>
#include <string>
#include <algorithm>

std::string reverse(std::string::iterator& it)
{
	char ch = *it;
	it++;
	if(ch != 'x')
		return std::string(1, ch);
	std::string uL = reverse(it);
	std::string uR = reverse(it);
	std::string lL = reverse(it);
	std::string lR = reverse(it);
	
	return std::string("x") + lL + lR + uL + uR;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int t; std::cin >> t;
	while(t--)
	{
		std::string str; std::cin >> str;
		std::string::iterator it = str.begin();
		std:: cout << reverse(it) << std::endl;
	}
}