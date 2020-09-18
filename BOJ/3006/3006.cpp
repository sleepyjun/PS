// https://www.acmicpc.net/problem/3006
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int input[100001];
int arr[300000];
struct SegTree {
	int size, leaf;
	SegTree(int n):size(n)
	{
		leaf = 1;
		while(leaf < size) leaf*=2;
	}
	void init()
	{
		for(int i = leaf-1; i > 0; --i)
			arr[i] = arr[i*2]+arr[i*2+1];
	}
	void update(int i, int v)
	{
		i+=leaf;
		arr[i] = v;
		for(i/=2; i > 0; i/=2)
			arr[i] = arr[i*2]+arr[i*2+1];
	}
	int query(int l, int r)
	{
		int res = 0;
		l+=leaf; r+=leaf;
		while(l<=r)
		{
			if(l%2 == 1) res += arr[l++];
			if(r%2 == 0) res += arr[r--];
			l/=2; r/=2;
		}
		return res;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	SegTree s(n);
	for(int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		input[x] = i;
	}
	for(int i = 0; i < n; ++i)
		arr[i+s.leaf] = 1;
	s.init();
	int left = 1, right = n;
	while(1)
	{
		int a = input[left++];
		cout << s.query(0,a-1)-1 << '\n';
		s.update(a-1, 0); 
		if(left >= right && n%2) break;
		a = input[right--];
		cout << s.query(a-1,n-1)-1 << '\n';
		s.update(a-1, 0);
		if(left >= right && !(n%2)) break;
	}
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;