#include    <iostream>

using namespace std;

#define INF 0x7FFFFFFF

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int V,min_cost;

    cin>>V;
    min_cost = INF;

    for(int a=1;a<=V;a++)
    {
        for(int b=1;b<=V;b++)
        {
            if( a*b > V )
            {
                break;
            }

            for(int c=1;c<=V;c++)
            {
                if( a*b*c > V )
                {
                    break;
                }

                if( a*b*c == V )
                {
                    min_cost = min(min_cost,2*(a*b+b*c+c*a));
                }
            }
        }
    }

    cout<<min_cost<<'\n';

    return  0;
}