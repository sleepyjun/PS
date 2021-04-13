// https://www.acmicpc.net/problem/16566
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

const int MAX = 8388608;
int arr[MAX];
struct SegTree {
    int leaf, size;
    SegTree(int n) : size(n)
    {
        leaf = 1;
        while(leaf < size) leaf *= 2;
        std::fill(arr, arr+MAX, INF);
    }

    void init()
    {
        for(int i = leaf-1; i > 0; --i)
            arr[i] = std::min(arr[i*2], arr[i*2+1]);
    }
    void update(int i, int v)
    {
        i += leaf;
        arr[i] = v;
        for(i/=2; i>=1; i/=2)
            arr[i] = std::min(arr[i*2], arr[i*2+1]);
    }
    int query(int l, int r)
    {
        int ret = INF;
        l += leaf; r += leaf;
        while(l < r)
        {
            if(l%2 == 1) ret = std::min(ret, arr[l++]);
            if(r%2 == 1) ret = std::min(ret, arr[--r]);
            l/=2; r/=2;
        }
        return ret;
    }
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m,k; cin >> n >> m >> k;
    SegTree s(n);
    for(int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        arr[s.leaf+x] = x;
    }
    s.init();
    while(k--)
    {
        int x; cin >> x;
        int ret = s.query(x+1,n+1);
        cout << ret << '\n';
        s.update(ret,INF);
    }
}//g++ -o a -std=c++11 *.cpp