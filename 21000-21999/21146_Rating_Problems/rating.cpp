#include    <iostream>

using namespace std;

#define LOW     -3.0
#define HIGH    3.0

#define get_avg()
int main(void)
{
    double n,k,fixed,avg1,avg2;

    scanf("%lf %lf",&n,&k);
    fixed = 0.0;

    for(double i=1.0;i<=k;i++)
    {
        double r;

        scanf("%lf",&r);
        fixed += r;
    }

    printf("%.04f %.04f\n",(fixed+(n-k)*LOW)/n,(fixed+(n-k)*HIGH)/n);

    return  0;
}