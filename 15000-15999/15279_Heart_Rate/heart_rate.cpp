#include    <iostream>

using namespace std;

int main(void)
{
    int N;

    scanf("%d",&N);

    for(int n=1;n<=N;n++)
    {
        double  b,p,bpm,diff;

        scanf("%lf %lf",&b,&p);

        bpm = 60*b/p;
        diff = bpm/b;

        printf("%.04f %.04f %.04f\n",bpm-diff,bpm,bpm+diff);
    }

    return  0;
}