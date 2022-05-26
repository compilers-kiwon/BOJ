#include    <iostream>
#include    <queue>

using namespace std;

typedef struct{double m,t,F;} FuelTank;

double  get_height(void)
{
    int     n;
    double  ret,v,M;

    queue<FuelTank> q;

    scanf("%d %lf",&n,&M);

    for(int i=1;i<=n;i++)
    {
        FuelTank    f;

        scanf("%lf %lf %lf",&f.m,&f.t,&f.F);
        
        M += f.m;
        q.push(f);

    }

    for(ret=v=0.0;!q.empty();q.pop())
    {
        FuelTank    f = q.front();

        ret += v*f.t+(f.F/M-9.81)*f.t*f.t/2.0;
        
        v += (f.F/M-9.81)*f.t;
        M -= f.m;
    }

    return  ret;
}

int     main(void)
{
    int K;

    scanf("%d",&K);

    for(int i=1;i<=K;i++)
    {
        printf("Data Set %d:\n%.02f\n",i,get_height());
    }

    return  0;
}