// https://www.acmicpc.net/problem/5670
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ll = long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

struct Trie {
	Trie *next[26];
	bool end;
	int branch;
	int word;
	
	Trie(): end(false), branch(0), word(0)
	{
		std::fill(next, next+26, nullptr);
	}
	~Trie()
	{
		for(int i = 0; i < 26; ++i)
			if(next[i] != nullptr) delete next[i];
	}
	
	void insert(const char *str)
	{
		if(*str == '\0')
		{
			branch++;
			end = true;
		}
		else
		{
			if(next[*str-'a'] == nullptr)
			{
				branch++;
				next[*str-'a'] = new Trie;
			}
			word++;
			next[*str-'a']->insert(str+1);
		}
	}
	
	ll count(bool isRoot = false)
	{
		ll res = 0;
		
		if(isRoot == true || branch > 1) res += word;
		for(int i = 0; i < 26; ++i)
			if(next[i]) res += next[i]->count();
		
		return res;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cout << std::fixed;
	cout.precision(2);
	
	while(1)
	{
		int n; cin >> n;
		if(cin.eof()) break;
		
		Trie *root = new Trie;
		
		for(int i = 0; i < n; ++i)
		{
			char str[81] = "\0";
			cin >> str;
			root->insert(str);
		}
		
		ll sum = root->count(true);
		
		cout << (1.0*sum)/n << '\n';
		
		delete root;
	}
	
	return 0;
}//g++ -o a -std=c++17 *.cpp