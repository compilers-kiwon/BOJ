#include    <iostream>
#include    <queue>

using namespace std;

typedef priority_queue<int> PQ;

#define MAX_NUM_OF_TRIALS   1440

#define queue_snow(n,pq)    {if((n)!=0)(pq).push(n);}

#define read_and_queue_snow(size,q)  \
    {for(int i=1;i<=(size);i++){int tmp;cin>>tmp;queue_snow((tmp),(q));}}

#define sweep_snow(snow,q)  {(snow)=(q).top()-1;(q).pop();}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,m;
    PQ  pq;

    cin>>N;
    read_and_queue_snow(N,pq);

    for(m=0;!pq.empty()&&m<MAX_NUM_OF_TRIALS;m++)
    {
        int n1,n2;

        if( pq.size() == 1 )
        {
            sweep_snow(n1,pq);n2 = 0;
        }
        else
        {
            sweep_snow(n1,pq);sweep_snow(n2,pq);
        }

        queue_snow(n1,pq);queue_snow(n2,pq);
    }

    cout<<(pq.empty()?m:-1)<<'\n';

    return  0;
}