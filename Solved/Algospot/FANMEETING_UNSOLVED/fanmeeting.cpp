#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::string member;
std::string fan;
//member cnt <= fan cnt;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int t; std::cin >> t;
	while(t--)
	{
		std::cin >> member;
		std::cin >> fan;
		std::vector<int> m(member.length());
		std::vector<int> f(fan.length());
		for(int i = 0; i < member.length(); ++i)
			m[i] = (member[i] == 'M');
		for(int i = 0; i < fan.length(); ++i)
			f[i] = (fan[i] == 'M');
			
	}
}