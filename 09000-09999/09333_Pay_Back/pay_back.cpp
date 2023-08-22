#include    <iostream>

using namespace std;

typedef long long int   int64;

#define MAX_MONTH           1200
#define IMPOSSIBLE          -1
#define get_interest(p,r)   (((p)*10*(r)/10000+5)/10)

int64   read_number(void)
{
    int64   a,b;

    scanf("%lld.%lld",&a,&b);
    return  a*100+b;
}

int input(int64& principal,int64& i_rate,int64& salary)
{
    i_rate = read_number();
    principal = read_number();
    salary = read_number();

    return  0;
}

int64   pay_back(int64 principal,int64 i_rate,int64 salary)
{
    principal += get_interest(principal,i_rate);
    principal -= salary;

    return  principal;
}

int simulate(int64 principal,int64 i_rate,int64 salary)
{
    for (int m=1;m<=MAX_MONTH;m++) {
        principal = pay_back(principal,i_rate,salary);
        if (principal <= 0) return  m;
    }

    return  IMPOSSIBLE;
}

int main(void)
{
    int T;

    scanf("%d",&T);

    for (int i=1;i<=T;i++) {
        int64   p,r,s;
        int     m;

        input(p,r,s);
        
        if ((m=simulate(p,r,s)) == IMPOSSIBLE) {
            puts("impossible");
        } else {
            printf("%d\n",m);
        }
    }

    return  0;
}