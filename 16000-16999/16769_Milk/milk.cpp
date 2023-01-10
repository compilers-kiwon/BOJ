#include    <iostream>

using namespace std;

#define MAX_NUM_OF_BUCKETS  3
#define NUM_OF_POURINGS     100
#define NEXT_BUCKET(b)      (((b)+1)%MAX_NUM_OF_BUCKETS)

void    pour_milk(int capacity[],
                    int milk[],int from,int to)
{
    int milk_to_be_moved = 
            min(capacity[to]-milk[to],milk[from]);

    milk[from] -= milk_to_be_moved;
    milk[to] += milk_to_be_moved;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int c[MAX_NUM_OF_BUCKETS];
    int m[MAX_NUM_OF_BUCKETS];

    for(int i=0;i<MAX_NUM_OF_BUCKETS;i++)
    {
        cin>>c[i]>>m[i];
    }

    for(int p=1,from=0,to=1;p<=NUM_OF_POURINGS;
            p++,from=NEXT_BUCKET(from),to=NEXT_BUCKET(to))
    {
        pour_milk(c,m,from,to);        
    }

    for(int i=0;i<MAX_NUM_OF_BUCKETS;i++)
    {
        cout<<m[i]<<'\n';
    }

    return  0;
}