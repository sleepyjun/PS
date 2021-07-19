// https://www.acmicpc.net/problem/3136
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pp = std::pair<pii, pii>;
const int INF = std::numeric_limits<int>::max();

std::set<pii> vertex;
std::set<pp> edge;
const int DIR[8][2] = {
	{-2, 0},
	{-2, 2},
	{ 0, 2},
	{ 2, 2},
	{ 2, 0},
	{ 2,-2},
	{ 0,-2},
	{-2,-2}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	pii curr(0,0);
	vertex.insert(curr);
	for(int i = 0; i < n; ++i)
	{
		char ch; cin >> ch;
		int d = ch-'0';

		pii node(curr.first + DIR[d][0],
			curr.second + DIR[d][1]);
		pii mid((curr.first + node.first)/2, 
			(curr.second + node.second)/2);
		
		vertex.insert(node);
		vertex.insert(mid);


		if(curr < node)
			edge.insert({curr, node});
		else edge.insert({node, curr});

		curr = node;
	}

	int face = 1-vertex.size()+edge.size()*2;

	cout << face << '\n';
}//g++ -o a -std=c++17 *.cpp