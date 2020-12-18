// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <tuple>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

using info = std::tuple<int, int, int, int, int>;
bool exist[101][101];
std::vector<info> shark;
enum {SIZE, DIR, SPEED, SY, SX};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
bool compareY(const info &a, const info &b)
{
    return std::get<SY>(a) < std::get<SY>(b);
}
void print()
{
    cout << "================================\n";
    for(int i = 0; i < shark.size(); ++i)
    {
        int z,d,s,y,x;
        std::tie(z,d,s,y,x) = shark[i];
        cout << z << ' ' << d << ' ' << s << ' ' << y << ' ' << x << '\n';
    }
    cout << "================================\n";
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int Y,X;
	cin >> Y >> X;
    int n; cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int y,x,s,d,z;
        cin >> y >> x >> s >> d >> z;
        shark.push_back({z,d,s,y,x});
    }

    int res = 0;
    for(int i = 1; i <= X; ++i)
    {
        std::sort(shark.begin(), shark.end(), compareY);
        auto it = shark.begin();
        while(it != shark.end())
        {
            int cx = std::get<SX>(*it);
            // int& cz = std::get<SIZE>(*it); 별차이없음..
            if(cx == i && cz != 0)
            {
                // res += cz;
                // cz = 0;
                res += std::get<SIZE>(*it);
                it = shark.erase(it);
                break;
            }
            else it++;
        }
        // CONDITION 1,2 CLEAR
        std::vector<info> temp;
        std::sort(shark.begin(), shark.end(), std::greater<info>());
        for(const auto &sh : shark)
        {
            int z,d,s,y,x;
            std::tie(z,d,s,y,x) = sh;
            int loop = (d < 3) ? 2*(Y-1) : 2*(X-1);
            loop = s%loop;
            for(int j = 0; j < loop; ++j)
            {
                if(d < 3)
                {
                    if(y==1 && d==1 ||y==Y && d==2)
                        d = (d==1) ? 2 : 1;
                    y += dy[d-1];
                }
                else
                {
                    if(x==1 && d==4 ||x==X && d==3)
                        d = (d==3) ? 4 : 3;
                    x += dx[d-1];
                }
            }
            if(exist[y][x] == true) continue;
            exist[y][x] = true;
            temp.push_back({z,d,s,y,x});
        }
        shark = temp;
        for(const auto &sh : shark)
        {
            int y = std::get<SY>(sh);
            int x = std::get<SX>(sh);
            exist[y][x] = false;
        }
    }

    cout << res << '\n';
}//g++ -o a -std=c++11 *.cpp