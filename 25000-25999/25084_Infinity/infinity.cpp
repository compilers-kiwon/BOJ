#include    <iostream>

using namespace std;

const double pi = 3.141592653589793;

typedef long long int   int64;

int main(void)
{
    int T;

    scanf("%d",&T);

    for(int t=1;t<=T;t++)
    {
        int64 R,A,B,area;

        scanf("%lld %lld %lld",&R,&A,&B);
        area = 0;

        for(int i=1;R!=0;i++)
        {
            area += R*R;

            if( i%2 == 1 )
            {
                R *= A;
            }
            else
            {
                R /= B;
            }
        }

        printf("Case #%d: %.06f\n",t,(double)area*pi);
    }

    return  0;
}