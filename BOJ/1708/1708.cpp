// https://www.acmicpc.net/problem/1708
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <stack>
using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

struct Point {
    int x,y,p,q;
    Point(int _x=0, int _y=0): x(_x), y(_y), p(0), q(0) {}
    bool operator <(const Point & P)
    {
        if(1LL*q*P.p != 1LL*p*P.q) return 1LL*q*P.p < 1LL*p*P.q; //탄젠트를 풀어 쓴 것..
        if(y != P.y) return y < P.y;
        return x < P.x;
    }
};
long long ccw(const Point &A, const Point &B, const Point &C) {
    return 1LL*(B.x-A.x)*(C.y-A.y)-1LL*(B.y-A.y)*(C.x-A.x);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
    Point p[n+1];
    for(int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
    std::sort(p,p+n);
    for(int i = 1; i < n; ++i)
    {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    std::sort(p+1,p+n);

    std::stack<int> s;
    s.push(0); s.push(1);
    int next = 2;
    while(next < n)
    {
        while(s.size() >= 2)
        {
            int a,b;
            b = s.top(); s.pop();
            a = s.top();
            if(ccw(p[a],p[b],p[next]) > 0)
            {
                s.push(b);
                break;
            }
        }
        s.push(next++);
    }
    cout << s.size() << '\n';
}//g++ -o a -std=c++11 *.cpp