// https://www.acmicpc.net/problem/1259
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    while(1)
    {
	    std::string str; cin >> str;
        if(str == "0") break;
        bool flag = true;
        int chk = str.length()/2;
        for(int i = 0; flag && i < chk; ++i)
        {
            if(str.at(i) != str.at(str.length()-1-i))
                flag = false;
        }
        if(true == flag) cout << "yes\n";
        else cout << "no\n";
    }
}//find . -type f -name "*.cpp" -exec g++ {} -o a -std=c++11 \;