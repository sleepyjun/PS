#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int x,y;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x>>y;
        cout<<x+y<<'\n';
    }
}
