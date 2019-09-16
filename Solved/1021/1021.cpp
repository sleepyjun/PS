#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;

int pivot[50];
/*
a.push_back(a.front());
			a.pop_front();
			acnt++;
		}
		while (!num[b.front()])
		{
			b.push_front(b.back());
			b.pop_back();
			bcnt++;
*/
int main()
{
    deque<int> dq;
    int n, m;
    int sum = 0;
    int idx = -1;
    scanf("%d %d",&n, &m);

    for(int i = 1; i <= n; ++i)
        dq.push_back(i);
    for(int i = 0; i < m; ++i)
        scanf("%d",&pivot[i]);
    
    while(idx != m-1)
    {
        idx++;
        
        if(dq.front() == pivot[idx])
        {
            dq.pop_front();
            continue;
        }

        deque<int> l, r;
        l = r = dq;

        for(int i = 1; i <= dq.size(); ++i)
        {
            l.push_back(l.front());
            l.pop_front();
            //left move
            r.push_front(r.back());
            r.pop_back();
            //right move

            if(r.front() == pivot[idx])
            {   
                r.pop_front();
                sum += i;
                dq = r;
                break;
            }
            if(l.front() == pivot[idx])
            {
                l.pop_front();
                sum += i;
                dq = l;
                break;
            }
        }
    }
    printf("%d", sum);
}