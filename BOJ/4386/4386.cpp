// https://www.acmicpc.net/problem/4386
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <cmath>

using std::cin; using std::cout;
using ull = unsigned long long;
using pdd = std::pair<double, double>;
const int INF = std::numeric_limits<int>::max();

struct edge {
    int s,e;
    double w;
    edge() : s(0), e(0), w(0) {}
    edge(int _s, int _e, double _w) :
        s(_s), e(_e), w(_w) {}
    bool operator < (const edge &a) const 
    {
        return this->w < a.w;
    }
};

double distance(double x1, double y1,
                double x2, double y2)
{
    double x = x1-x2;
    double y = y1-y2;
    return sqrt((x*x)+(y*y));
}
int p[101];
int find(int n)
{
    if(p[n] == -1) return n;
    return p[n] = find(p[n]);
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
	
	cout << std::fixed;
    cout.precision(2);
    double x[101], y[101];
    std::vector<edge> g;
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            double w = distance(x[i], y[i], x[j], y[j]);
            g.push_back(edge(i,j,w));
        }
    }
    std::sort(g.begin(),g.end());
    std::fill(p,p+101,-1);

    int cnt=0;
    double res=0;
    for(const auto &E : g)
    {
        if(cnt == n-1) break;
        if(merge(E.s,E.e))
        {
            res += E.w;
            cnt++;
        }
    }
    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp