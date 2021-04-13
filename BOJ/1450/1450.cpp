// https://www.acmicpc.net/problem/1450
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

int n,c; 
std::vector<int> arr1, arr2, psum;
std::map<ull, int> map1, map2;
std::vector<std::pair<ull, int> > sum1, sum2;

int search(ull x)
{
	int l = 0, r = sum2.size()-1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(sum2[mid].first <= x) l = mid+1;
		else r = mid-1;
	}
	l--;
	if(l < 0) return 0;
	else return psum[l];
}
void dfs1(ull sum=0, int curr=0)
{
	if(curr == arr1.size())
	{
		auto it = map1.find(sum);
		if(it != map1.end()) map1[sum]++;
		else map1[sum] = 1;
		return;
	}
	dfs1(sum+arr1[curr], curr+1);
	dfs1(sum, curr+1);
}
void dfs2(ull sum=0, int curr=0)
{
	if(curr == arr2.size())
	{
		auto it = map2.find(sum);
		if(it != map2.end()) map2[sum]++;
		else map2[sum] = 1;
		return;
	}
	dfs2(sum+arr2[curr], curr+1);
	dfs2(sum, curr+1);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> c;

	for(int i = 0; i < n/2; ++i)
	{
		int x; cin >> x;
		arr1.push_back(x);
	}
	for(int i = n/2; i < n; ++i)
	{
		int x; cin >> x;
		arr2.push_back(x);
	}
	dfs1(), dfs2();
	map1.erase(0), map2.erase(0);
	int res = 1;
	
	sum1 = std::vector<std::pair<ull, int> >(map1.begin(), map1.end()),
	sum2 = std::vector<std::pair<ull, int> >(map2.begin(), map2.end());
	
	psum.push_back(sum2[0].second);
	for(int i = 1; i < sum2.size(); ++i)
		psum.push_back(psum.back()+sum2[i].second);

	for(int i = 0; i < sum1.size(); ++i)
	{
		if(sum1[i].first > c) break;
		res += sum1[i].second * (1+search(c-sum1[i].first));
	}
	for(int i = 0; i < sum2.size(); ++i)
	{
		if(sum2[i].first > c) break;
		res += sum2[i].second;
	}
	cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp