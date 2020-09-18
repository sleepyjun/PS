#include <iostream>
#include <algorithm>
#include <limits>
#include <list>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--)
	{
		std::string str; cin >> str;
		std::list<char> l;
		auto it = l.end();
		for(int i = 0; i < str.length(); ++i)
		{
			if(str[i] == '<')
			{
				if(it == l.begin()) continue;
				it--;
			}
			else if(str[i] == '>')
			{
				if(it == l.end()) continue;
				it++;
			}
			else if(str[i] == '-')
			{
				if(it == l.begin()) continue;
				auto temp = it;
				temp--;
				l.erase(temp);
			}
			else
			{
				l.insert(it, str[i]);
			}
		}
		
		for(auto it = l.begin(); it != l.end(); ++it)
			cout << *it;
		cout << '\n';
	}
}