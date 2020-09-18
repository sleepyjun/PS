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
	
	std::string str; cin >> str;
	int n; cin >> n;
	std::list<char> l;
	for(int i = 0; i < str.length(); ++i)
		l.push_back(str[i]);
	
	auto it = l.end();
	while(n--)
	{
		char command; cin >> command;
		auto temp = it;
		switch(command){
		case 'L':
			if(it == l.begin()) continue;
			it--;
			break;
		case 'D':
			if(it == l.end()) continue;
			it++;
			break;
		case 'B':
			if(it == l.begin()) continue;
			temp--;
			l.erase(temp);
			break;
		case 'P':
			char ch; cin >> ch;
			l.insert(it, ch);
			break;
		}
	}
	
	for(auto it = l.begin(); it != l.end(); ++it)
		cout << *it;
	cout << '\n';
}