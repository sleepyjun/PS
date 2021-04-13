// https://www.acmicpc.net/problem/14725
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

struct Tree {
	std::map<std::string, Tree*> children;

	void insert(const std::vector<std::string> &arr, int idx = 0)
	{
		if(idx == arr.size()) return;

		auto it = children.find(arr[idx]);
		if(it == children.end())
		{
			Tree *child = new Tree;
			children.insert({arr[idx], child});
			child->insert(arr, idx+1);
		}
		else it->second->insert(arr, idx+1);
	}

	void print(int depth=0)
	{
		if(children.size() == 0) return;

		for(const auto &p : children)
		{
			for(int i = 0; i < depth; ++i) cout << "--";
			cout << p.first << '\n';
			p.second->print(depth+1);
		}
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	Tree t;
	int n; cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int k; cin >> k;
		std::vector<std::string> arr(k);
		
		for(int j = 0; j < k; ++j)
			cin >> arr[j];
		
		t.insert(arr);
	}

	t.print();
}//g++ -o a -std=c++11 *.cpp