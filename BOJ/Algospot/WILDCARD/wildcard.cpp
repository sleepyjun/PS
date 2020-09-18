#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> res;

bool func(const std::string& wc, 
		  const std::string& str)
{
	int pos = 0;
	while(pos < wc.size() && pos < str.size() &&
		 (wc[pos] == '?' || wc[pos] == str[pos]))
	{
		pos++;
	}
	if(wc.size() == pos && str.size() == pos)
	{ return true; }
	
	if(wc[pos] == '*')
	{
		for(int cnt = 0; pos+cnt <= str.size(); ++cnt)
		{
			if(func(wc.substr(pos+1), str.substr(pos+cnt)))
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	int t; std::cin >> t;
	while(t--)
	{
		res.clear();
		
		std::string wc; std::cin >> wc;
		int n; std::cin >> n;
		
		for(int i = 0; i < n; ++i)
		{
			std::string str; std::cin >> str;
			if(func(wc, str)) res.push_back(str);
		}
		std::sort(res.begin(), res.end());
		for(int i = 0; i < res.size(); ++i)
			std::cout << res[i] << '\n';
	}
}