#include    <iostream>

using namespace std;

int main(void)
{
    int N;

    scanf("%d",&N);

    for(int i=1;i<=N;i++)
    {
        double  P,C;

        scanf("%lf %lf",&P,&C);
        printf("%.9f\n",100.0*P/(C+100.0));
    }

    return  0;
}