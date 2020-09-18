#include <cstdio>

 

using namespace std;

 

int gcd(int n, int m)

{

    int t;

    while(m)

    {

        t = n % m;

        n = m;

        m = t;

    }

    

    return n;

}

int main()

{

   int n,m;

   char ch;

   scanf("%d%c%d", &n, &ch, &m);

   int tmp;

 

   tmp = gcd(n,m);

   

   printf("%d%c%d\n",n/tmp, ch, m/tmp);

}

