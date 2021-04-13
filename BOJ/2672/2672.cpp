// https://www.acmicpc.net/problem/2672
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <set>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

struct Rect {
    double x,y,w,h;
    double xw,yh;
    Rect():x(0),y(0),w(0),h(0) {}
    Rect(double _x, double _y, double _w, double _h)
        :x(_x),y(_y),w(_w),h(_h) { this->xw = x+w; this->yh = y+h; }
    bool position(double x, double y) const
    {
        if(this->x <= x && x <= this->xw)
            if(this->y <= y && y <= this->yh)
                return true;
        return false;
    }
    // bool operator < (const Rect & B)
    // {
    //     if(this->y != B.y) return this->y < B.y;
    //     return this->x < B.x;
    // }
};
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
    std::vector<Rect> v(n);
    std::vector<double> xArr, yArr;
    std::set<double> xSet, ySet;
    for(int i = 0; i < n; ++i)
    {
        double x,y,w,h; cin >> x >> y >> w >> h;
        v[i] = Rect(x,y,w,h);
        xSet.insert(x); xSet.insert(x+w);
        ySet.insert(y); ySet.insert(y+h);
    }
    xArr = std::vector<double>(xSet.begin(), xSet.end());
    yArr = std::vector<double>(ySet.begin(), ySet.end());

    double res = 0;
    for(int i = 0; i < yArr.size()-1; ++i)
    {//좌상단 우하단 좌표
        double y1 = yArr[i];
        double y2 = yArr[i+1];
        for(int j = 0; j < xArr.size()-1; ++j)
        {//좌상단 우하단 좌표
            double x1 = xArr[j];
            double x2 = xArr[j+1];
            for(const Rect &r : v)
            {
                if(r.position(x1,y1) && r.position(x2,y2))
                {
                    res += (y2-y1)*(x2-x1);
                    break;
                }
            }
        }
    }

    if((int)(res*10)%10 != 0)
    {
        cout << std::fixed;
        cout.precision(2);
        cout << res;
    }
    else cout << (int)res;
    cout << '\n';
}//g++ -o a -std=c++11 *.cpp