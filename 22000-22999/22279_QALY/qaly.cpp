#include    <iostream>

using namespace std;

int main(void)
{
    int     N;
    double  qaly = 0.0;

    scanf("%d",&N);

    for(int i=1;i<=N;i++)
    {
        double  q,y;

        cin>>q>>y;
        qaly += q*y;
    }

    printf("%.3f\n",qaly);

    return  0;
}