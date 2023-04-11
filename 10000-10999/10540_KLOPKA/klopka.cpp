#include    <iostream>

using namespace std;

#define MAX_SIZE    100

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,min_X,min_Y,max_X,max_Y;

    cin>>N;

    min_X = min_Y = MAX_SIZE;
    max_X = max_Y = 0;

    for(int i=1;i<=N;i++)
    {
        int X,Y;

        cin>>X>>Y;

        min_X = min(min_X,X);
        min_Y = min(min_Y,Y);

        max_X = max(max_X,X);
        max_Y = max(max_Y,Y);
    }

    int dx = max_X-min_X;
    int dy = max_Y-min_Y;

    cout<<max(dx,dy)*max(dx,dy)<<'\n';

    return  0;
}