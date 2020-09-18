// https://www.acmicpc.net/problem/10597
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
const int INF = std::numeric_limits<int>::max();

bool find = false;
bool visited[51];
std::string str;
std::vector<int> res;

void func(int idx) 
{
	if(find == true) return;
	if(idx >= str.length()) {
		bool flag = true;
		int maxN = 0;
		for(int i = 50; !maxN && i >= 1; --i) 
			if(visited[i] == true) maxN = i;
		for(int i = 1; i <= maxN; ++i)
			if(visited[i] != true) flag = false;
		if(flag)
		{
			for(int i = 0; i < res.size(); ++i)
				cout << res[i] << ' ';
			cout << '\n';
			find = true;
		}
		return;
	}
	
	for(int i = 1; i <= 2; ++i) {
		int temp = std::stoi(str.substr(idx,i));
		if(temp > 50 || visited[temp] == true) continue;
		visited[temp] = true;
		res.push_back(temp);
		func(idx+i);
		res.pop_back();
		visited[temp] = false;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> str;
	func(0);
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;