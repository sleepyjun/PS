// https://www.acmicpc.net/problem/2887
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

struct V{
    int x,y,z,i;
    V() : x(0), y(0), z(0), i(0) {}
    V(int _x, int _y, int _z, int _i=0) :
        x(_x), y(_y), z(_z), i(_i) {}
};
bool compareX(const V &a, const V &b) { return a.x < b.x; }
bool compareY(const V &a, const V &b) { return a.y < b.y; }
bool compareZ(const V &a, const V &b) { return a.z < b.z; }
std::vector<V> location, adj;
int p[100001];
int find(int x)
{
    if(p[x] == -1) return x;
    return p[x] = find(p[x]);
}
bool merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return false;
    p[b] = a;
    return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    std::fill(p,p+100001,-1);
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x,y,z; cin >> x >> y >> z;
        location.push_back(V(x,y,z,i));
    }

    std::sort(location.begin(), location.end(), compareX);
    for(int i = 0; i < n-1; ++i)
    {
        int min = std::abs(location[i].x-location[i+1].x);
        int a = location[i].i;
        int b = location[i+1].i;
        if(a > b) std::swap(a,b);
        adj.push_back(V(a,b,min));
    }
    std::sort(location.begin(), location.end(), compareY);
    for(int i = 0; i < n-1; ++i)
    {
        int min = std::abs(location[i].y-location[i+1].y);
        int a = location[i].i;
        int b = location[i+1].i;
        if(a > b) std::swap(a,b);
        adj.push_back(V(a,b,min));
    }
    std::sort(location.begin(), location.end(), compareZ);
    for(int i = 0; i < n-1; ++i)
    {
        int min = std::abs(location[i].z-location[i+1].z);
        int a = location[i].i;
        int b = location[i+1].i;
        if(a > b) std::swap(a,b);
        adj.push_back(V(a,b,min));
    }
    
    int res = 0;
    int cnt = 0;
    std::sort(adj.begin(),adj.end(),compareZ);
    for(const V &v : adj)
    {
        if(cnt == n-1) break;
        int a=v.x, b=v.y, w=v.z;
        if(true == merge(a,b))
        {
            res += w;
            cnt++;
        }
    }

    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp