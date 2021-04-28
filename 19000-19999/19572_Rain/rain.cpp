#include    <iostream>

using namespace std;

int main(void)
{
    double  d1,d2,d3,a,b,c;

    scanf("%lf %lf %lf",&d1,&d2,&d3);

    b = (d3-d2+d1)/2.0;
    a = d1-b;
    c = d3-b;

    if( a>0.0 && b>0.0 && c>0.0 )
    {
        printf("1\n%.01f %.01f %.01f\n",a,b,c);
    }
    else
    {
        puts("-1");
    }

    return  0;
}