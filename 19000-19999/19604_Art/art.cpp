#include    <iostream>

using namespace std;

#define MAX_SIZE    100

int main(void)
{
    int N,left,right,top,bottom;

    scanf("%d",&N);

    left = bottom = MAX_SIZE;
    right = top = 0;

    for(int i=1;i<=N;i++)
    {
        int X,Y;

        scanf("%d,%d",&X,&Y);

        left = min(left,X);
        right = max(right,X);

        bottom = min(bottom,Y);
        top = max(top,Y);
    }

    printf("%d,%d\n%d,%d\n",left-1,bottom-1,right+1,top+1);

    return  0;
}