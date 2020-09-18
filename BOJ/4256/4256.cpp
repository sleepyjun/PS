// https://www.acmicpc.net/problem/4256
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

std::vector<int> pre, in;

void make_post(int preFirstIdx, int preLastIdx,
			  int inFirstIdx, int inLastIdx)
{
	int size = preLastIdx - preFirstIdx + 1;
	int preRootIdx = preFirstIdx;
	int root = pre[preRootIdx];
	int inRootIdx = std::find(in.begin(), in.end(), root) - in.begin();
	int leftSubSize = inRootIdx - inFirstIdx;
	int rightSubSize = size - leftSubSize - 1;
	
	if(leftSubSize != 0)
		make_post(preRootIdx+1, preRootIdx+leftSubSize,
				 inFirstIdx, inRootIdx-1);
	if(rightSubSize != 0)
		make_post(preRootIdx+leftSubSize+1, preLastIdx,
				 inRootIdx+1, inLastIdx);
	cout << root << ' ';
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		pre.clear(); pre.reserve(n);
		in.clear(); in.reserve(n);
		for(int i = 0; i < n; ++i)
		{
			int node; cin >> node;
			pre.push_back(node);
		}
		
		for(int i = 0; i < n; ++i)
		{
			int node; cin >> node;
			in.push_back(node);
		}
		make_post(0,n-1,0,n-1);
		cout << '\n';
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;