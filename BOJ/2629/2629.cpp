// https://www.acmicpc.net/problem/2629
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int n;
bool weight[31][60000];
std::vector<int> sinker;
void init(int idx, int w)
{
	if(idx == n+1) return;
	if(weight[idx][w]) return;
	weight[idx][w] = true;

	init(idx+1,w+sinker[idx]);
	init(idx+1,w);
	init(idx+1,w-sinker[idx]);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n; sinker.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> sinker[i];
	init(0,15000);
	int m; cin >> m;
	for(int i = 0; i < m; ++i)
	{
		bool flag = true;
		int w; cin >> w;
		for(int j = 1; flag && j <= n; ++j)
		{

			if(weight[j][15000+w])
			{
				cout << "Y ";
				flag = false;
			}
		}
		if(flag)
			cout << "N ";
	}
}//g++ -o a -std=c++11 *.cpp