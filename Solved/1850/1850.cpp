#include <cstdio>

typedef unsigned long long ull;

 

ull gcd(ull n, ull m)

{

    ull t;

    while(m)

    {

        t = n%m;

        n = m;

        m = t;

    }

    return n;

}

int main()

{

   ull n, m;

   scanf("%llu %llu", &n, &m);

   

   for(int i = 0; i < gcd(n,m); ++i)

       printf("1");

    printf("\n");

}

