#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    vector<int> V;
    queue<int> Q;
    int N,M; // 1 <= M <= N <= 1000
    int temp;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        Q.push(i+1);



    if( M != 1)
    {
        cout << '<';

        while(Q.size() != M)
        {
            for(int i = 1; i < M; ++i)
            {
                V.push_back(Q.front());
                Q.pop();
            }
            cout << Q.front() <<", ";
            Q.pop();
            for(int i = 0; i < M - 1; ++i)
                Q.push(V[i]);
            V.clear();
        }
        cout << Q.back() << ", ";
        for(int i = 0; i < M - 2; ++i)
        {
            cout << Q.front() << ", ";
            Q.pop();
        }
            cout << Q.front() << '>';
    }
    else
    {
        cout << '<';
        for(int i = 1; i <= N-1 ; ++i)
            cout << i << ", ";
        cout << N << '>';

    }
}
