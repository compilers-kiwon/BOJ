#include    <iostream>

using namespace std;

int main(void)
{
    int t1,t2,diff,length;

    scanf("%d %d",&t1,&t2);

    for(length=2;!(t1<t2);length++)
    {
        diff = t1-t2;
        t1 = t2;
        t2 = diff;
    }

    printf("%d\n",length);

    return  0;
}