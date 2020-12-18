// https://www.acmicpc.net/problem/1647
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using tuple = std::tuple<int, int, int>;
const int INF = std::numeric_limits<int>::max();

int p[100001];
int find(int n)
{
    if(p[n] == -1) return n;
    p[n] = find(p[n]);
    return p[n];
}
bool merge(int a, int b)
{
    a = find(a); b = find(b);
    if(a==b) return false;
    p[b] = a;
    return true;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    std::fill(p,p+100001,-1);
	int n, m; cin >> n >> m;
    std::vector<tuple> v;
    for(int i = 0; i < m; ++i)
    {
        int a,b,w; cin >> a >> b >> w;
        v.push_back(std::make_tuple(w,a,b));
    }
    std::sort(v.begin(), v.end());
    int sum = 0;
    int cnt = 0;
    for(const auto &r : v)
    {
        if(cnt == n-2) break;
        int a,b,w;
        std::tie(w,a,b) = r;
        if(true == merge(a,b))
        {
            sum += w;
            cnt++;
        }
    }
    cout << sum << '\n';
}//g++ -o a -std=c++11 *.cpp