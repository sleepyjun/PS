// https://www.acmicpc.net/problem/5676
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 400000;
int arr[MAX];
struct SegTree {
	int size, leaf;
	SegTree(int n) : size(n) {
		leaf = 1;
		while(leaf < size) leaf *= 2;
	}
	void init() {
		for(int i=leaf-1; i>0; --i)
			arr[i] = arr[i*2]*arr[i*2+1];
	}
	
	void update(int i, int v) {
		i += leaf;
		if(v>0) arr[i] = 1;
		else if(v<0) arr[i] = -1;
		else arr[i] = 0;
		for(i/=2; i>=1; i/=2)
			arr[i] = arr[i*2]*arr[i*2+1];
	}
	
	int query(int l, int r) {
		int res = 1;
		l += leaf; r += leaf;
		while(l<=r) {
			if(l%2 == 1) res *= arr[l++];
			if(r%2 == 0) res *= arr[r--];
			l/=2; r/=2;
		}
		return res;
	}
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(!cin.eof()) {
		std::fill(arr,arr+MAX,1);
		int n, k; cin >> n >> k;
		SegTree s(n);
		for(int i = 0; i < n; ++i) {
			int x; cin >> x;
			if(x>0) arr[i+s.leaf] = 1;
			else if(x<0) arr[i+s.leaf] = -1;
			else arr[i+s.leaf] = 0;
		} s.init();
		for(int i = 0; i < k; ++i) {
			char ch;
			int a,b; 
			cin >> ch >> a >> b;
			if(cin.eof() == true) return 0;
			if(ch == 'C') s.update(a-1,b);
			else if(ch == 'P') {
				int res = s.query(a-1,b-1);
				
				if(res>0) cout << '+';
				else if(res<0) cout << '-';
				else cout << '0';
			}
		}
		cout << '\n';
	}
	
	
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;