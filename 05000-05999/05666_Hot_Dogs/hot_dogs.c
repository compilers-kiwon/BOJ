#include    <stdio.h>

int main(void)
{
    for(float H,P;scanf("%f %f",&H,&P)==2;)
    {
        printf("%.02f\n",H/P);
    }

    return  0;
}