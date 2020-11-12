// https://www.acmicpc.net/problem/9935
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

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::string str, bomb; cin >> str >> bomb;
    std::stack<char> s;
    for(char ch : str)
    {
        std::stack<char> temp;
        s.push(ch);
        if(s.size() >= bomb.length())
        {
            bool flag = true;
            for(int i = bomb.length()-1; flag && i >= 0; --i)
            {
                if(s.top() == bomb[i])
                {
                    temp.push(s.top());
                    s.pop();
                }
                else flag = false;
            }
            if(flag == false)
            {
                while(!temp.empty())
                {
                    s.push(temp.top());
                    temp.pop();
                }
            }
        }
    }
    
    if(false == s.empty())
    {
        std::string res;
        while(!s.empty())
        {
            res += s.top();
            s.pop();
        }
        std::reverse(res.begin(), res.end());
        cout << res;
    }
    else cout << "FRULA";
    cout << '\n';
}//g++ -o a -std=c++11 *.cpp